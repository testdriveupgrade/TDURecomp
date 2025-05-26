import numpy as np
from pydub import AudioSegment
import sys
import io
import scipy.io.wavfile

sound = AudioSegment.from_file(sys.argv[1])
channel_sounds = sound.split_to_mono()
samples = [s.get_array_of_samples() for s in channel_sounds]
fp_arr = np.array(samples).T.astype(np.float32)
fp_arr /= np.iinfo(samples[0].typecode).max

C0, C1, C2, C3, C4, C5 = fp_arr.T 
L = C0 + C2 * 0.75 + C4
R = C1 + C2 * 0.75 + C5
fp_arr = np.column_stack((L, R))

wav_io = io.BytesIO()
scipy.io.wavfile.write(wav_io, sound.frame_rate, fp_arr)
wav_io.seek(0)
sound = AudioSegment.from_wav(wav_io)

sound.export(sys.argv[2], format="ogg", parameters=["-q:a", "6"])