import argparse
import logging
import subprocess
import os

logger = logging.getLogger("audio.py")


def create_empty(input: str):
    logger.info(f"creating empty: {input}")
    subprocess.call(['ffmpeg',
                     '-f', 'lavfi',
                     '-i', 'anullsrc',
                     '-t', '300',
                    '-y',
                    input])


def mp3_to_wav(input: str):
    logger.info(f"converting: {input}")
    output = f"{input}.wav"
    if(input.endswith(".mp3")):
        output = input[:-4] + ".wav"
    subprocess.call(['ffmpeg', '-y', '-i', input,
                    # "-af", "highpass=f=200,lowpass=f=800",
                     '-f', 'wav',
                     '-acodec', 'pcm_u8',
                     '-ar', '32000',
                    #  '-ar', '31000',
                    #  '-ar', '27000',
                    #  '-ar', '16000',
                     output])

def wav_slice(input: str, start: str, end: str, out_prefix: str):
    subprocess.call(["ffmpeg",
                     "-y",
                     "-i", input,
                     "-ss", start,
                     "-to", end,
                     out_prefix])    


def wav_to_chunked(input: str, out_prefix: str):
    logger.info(f"wav: {input}")
    subprocess.call(["ffmpeg",
                     "-y",
                     "-i", input,
                     "-f", "segment",
                     "-segment_time", "5",
                     "-c", "copy",
                     f"{out_prefix}_%03d.wav"])


def wav_compress(input: str, out_prefix: str):
    # https://superuser.com/questions/1104534/how-to-use-compressor-with-ffmpeg
    basename = os.path.basename(input)
    subprocess.call(["ffmpeg",
                     "-y",
                    #  '-acodec', 'pcm_u8',
                     "-i", input,
                    "-af", 'anlmdn=strength=1.01111:p=0.002:r=0.004:m=11',
                     '-f', 'wav',
                     '-acodec', 'pcm_u8',
                    #  '-ar', '16000',
                    # '-ar', '27000',
                     '-ar', '31000',
                     f"{out_prefix}_{basename}"])


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    parser = argparse.ArgumentParser(
        prog="audio",
        description="various audio utilities",
    )
    parser.add_argument("-i", "--input")
    parser.add_argument("-e", "--create_empty", action=argparse.BooleanOptionalAction)
    parser.add_argument("-m", "--mp3_to_wav", action=argparse.BooleanOptionalAction)
    parser.add_argument("-s", "--wav_slice", action=argparse.BooleanOptionalAction)
    parser.add_argument("-c", "--wav_to_chunked", action=argparse.BooleanOptionalAction)
    parser.add_argument("-x", "--wav_compress", action=argparse.BooleanOptionalAction)
    parser.add_argument("-p", "--out_prefix", default="out")
    parser.add_argument("-ss", "--slice_start", default="00:00:00")
    parser.add_argument("-se", "--slice_end", default="00:00:30")
    args = parser.parse_args()
    if args.create_empty:
        create_empty(args.input)
    elif args.mp3_to_wav:
        mp3_to_wav(args.input)
    elif args.wav_slice:
        wav_slice(args.input, args.slice_start, args.slice_end, args.out_prefix)
    elif args.wav_to_chunked:
        wav_to_chunked(args.input, args.out_prefix)
    elif args.wav_compress:
        wav_compress(args.input, args.out_prefix)
    else:
        logger.error("no command flag specified") 