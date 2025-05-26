import ida_search
import ida_bytes
import ida_segment
import ida_name
import ida_funcs
import ida_kernwin
import ida_idaapi

def search_signature(pattern_bytes, function_name, description):
    """
    Search for a byte pattern in the loaded binary and return all found addresses.
    
    Args:
        pattern_bytes: Byte pattern as string (e.g., "e9 c1 ff 68")
        function_name: Name of the function to create
        description: Description of what this function does
    
    Returns:
        List of addresses where the pattern was found
    """
    print(f"\nSearching for {function_name}...")
    print(f"Pattern: {pattern_bytes}")
    print(f"Description: {description}")
    
    found_addresses = []
    
    # Start searching from the beginning of the first segment to end of last segment
    first_seg = ida_segment.get_first_seg()
    last_seg = ida_segment.get_last_seg()
    
    if first_seg is None or last_seg is None:
        print("  Error: No segments found in the binary")
        return []
    
    start_ea = first_seg.start_ea
    end_ea = last_seg.end_ea
    
    # Convert hex string to proper format for IDA search
    # Remove spaces and format as "XX XX XX XX"
    clean_pattern = pattern_bytes.replace(" ", "")
    if len(clean_pattern) % 2 != 0:
        print(f"  Error: Invalid pattern length for {function_name}")
        return []
    
    # Format pattern for IDA binary search (space-separated hex bytes)
    formatted_pattern = " ".join([clean_pattern[i:i+2] for i in range(0, len(clean_pattern), 2)])
    
    # Search for the pattern
    current_ea = start_ea
    search_count = 0
    max_searches = 1000  # Prevent infinite loops
    
    while current_ea < end_ea and current_ea != ida_idaapi.BADADDR and search_count < max_searches:
        search_count += 1
        
        # Search for the pattern using binary search
        try:
            found_ea = ida_search.find_binary(current_ea, end_ea, formatted_pattern, 16, ida_search.SEARCH_DOWN)
        except Exception as e:
            print(f"  Error during search: {str(e)}")
            break
        
        if found_ea == ida_idaapi.BADADDR:
            break
            
        found_addresses.append(found_ea)
        print(f"  Found at: 0x{found_ea:08X}")
        
        # Create function if it doesn't exist
        existing_func = ida_funcs.get_func(found_ea)
        if not existing_func:
            if ida_funcs.add_func(found_ea):
                print(f"    Created function at 0x{found_ea:08X}")
            else:
                print(f"    Failed to create function at 0x{found_ea:08X}")
        else:
            print(f"    Function already exists at 0x{found_ea:08X}")
        
        # Set function name
        current_name = ida_name.get_name(found_ea)
        if not current_name or current_name.startswith("sub_") or current_name.startswith("loc_"):
            if ida_name.set_name(found_ea, function_name, ida_name.SN_CHECK):
                print(f"    Named function: {function_name}")
            else:
                # If name already exists, try with suffix
                suffix = 1
                while suffix < 100:  # Prevent infinite loop
                    new_name = f"{function_name}_{suffix}"
                    if ida_name.set_name(found_ea, new_name, ida_name.SN_CHECK):
                        print(f"    Named function: {new_name}")
                        break
                    suffix += 1
        else:
            print(f"    Function already named: {current_name}")
        
        # Add comment
        try:
            ida_bytes.set_cmt(found_ea, description, False)
            print(f"    Added comment")
        except Exception as e:
            print(f"    Failed to add comment: {str(e)}")
        
        # Continue searching from next byte
        current_ea = found_ea + 1
    
    if not found_addresses:
        print(f"  Pattern not found")
    
    return found_addresses

def main():
    """
    Main function to search for all PowerPC runtime function signatures.
    """
    print("PowerPC Runtime Function Signature Scanner")
    print("=" * 50)
    
    # Define the signatures to search for
    signatures = [
        {
            "pattern": "e9 c1 ff 68",
            "name": "__restgprlr_14",
            "description": "Restore GPR and LR function starting with ld r14, -0x98(r1)"
        },
        {
            "pattern": "f9 c1 ff 68", 
            "name": "__savegprlr_14",
            "description": "Save GPR and LR function starting with std r14, -0x98(r1)"
        },
        {
            "pattern": "c9 cc ff 70",
            "name": "__restfpr_14", 
            "description": "Restore FPR function starting with lfd f14, -0x90(r12)"
        },
        {
            "pattern": "d9 cc ff 70",
            "name": "__savefpr_14",
            "description": "Save FPR function starting with stfd f14, -0x90(r12)"
        },
        {
            "pattern": "39 60 fe e0 7d cb 60 ce",
            "name": "__restvmx_14",
            "description": "Restore VMX function starting with li r11, -0x120; lvx v14, r11, r12"
        },
        {
            "pattern": "39 60 fe e0 7d cb 61 ce",
            "name": "__savevmx_14", 
            "description": "Save VMX function starting with li r11, -0x120; stvx v14, r11, r12"
        },
        {
            "pattern": "39 60 fc 00 10 0b 60 cb",
            "name": "__restvmx_64",
            "description": "Restore VMX function starting with li r11, -0x400; lvx128 v64, r11, r12"
        },
        {
            "pattern": "39 60 fc 00 10 0b 61 cb", 
            "name": "__savevmx_64",
            "description": "Save VMX function starting with li r11, -0x400; stvx128 v64, r11, r12"
        }
    ]
    
    all_results = {}
    
    # Search for each signature
    for sig in signatures:
        addresses = search_signature(sig["pattern"], sig["name"], sig["description"])
        all_results[sig["name"]] = addresses
    
    # Print summary
    print("\n" + "=" * 50)
    print("SUMMARY")
    print("=" * 50)
    
    total_found = 0
    for func_name, addresses in all_results.items():
        count = len(addresses)
        total_found += count
        if count > 0:
            print(f"{func_name}: {count} instance(s) found")
            for addr in addresses:
                print(f"  - 0x{addr:08X}")
        else:
            print(f"{func_name}: Not found")
    
    print(f"\nTotal functions found: {total_found}")
    
    if total_found > 0:
        print("\nFunctions have been created and named in the IDA database.")
        print("Comments have been added with descriptions.")
    
    return all_results

# Run the scanner
if __name__ == "__main__":
    try:
        results = main()
        ida_kernwin.info("PowerPC signature scan completed. Check output window for results.")
    except Exception as e:
        print(f"Error during scan: {str(e)}")
        ida_kernwin.warning(f"Error during scan: {str(e)}")