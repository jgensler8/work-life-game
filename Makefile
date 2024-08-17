#---------------------------------------------------------------------------------------------------------------------
# TARGET is the name of the output.
# BUILD is the directory where object files & intermediate files will be placed.
# LIBBUTANO is the main directory of butano library (https://github.com/GValiente/butano).
# PYTHON is the path to the python interpreter.
# SOURCES is a list of directories containing source code.
# INCLUDES is a list of directories containing extra header files.
# DATA is a list of directories containing binary data.
# GRAPHICS is a list of files and directories containing files to be processed by grit.
# AUDIO is a list of files and directories containing files to be processed by mmutil.
# DMGAUDIO is a list of files and directories containing files to be processed by mod2gbt and s3m2gbt.
# ROMTITLE is a uppercase ASCII, max 12 characters text string containing the output ROM title.
# ROMCODE is a uppercase ASCII, max 4 characters text string containing the output ROM code.
# USERFLAGS is a list of additional compiler flags:
#     Pass -flto to enable link-time optimization.
#     Pass -O0 or -Og to try to make debugging work.
# USERCXXFLAGS is a list of additional compiler flags for C++ code only.
# USERASFLAGS is a list of additional assembler flags.
# USERLDFLAGS is a list of additional linker flags:
#     Pass -flto=<number_of_cpu_cores> to enable parallel link-time optimization.
# USERLIBDIRS is a list of additional directories containing libraries.
#     Each libraries directory must contains include and lib subdirectories.
# USERLIBS is a list of additional libraries to link with the project.
# DEFAULTLIBS links standard system libraries when it is not empty.
# STACKTRACE enables stack trace logging when it is not empty.
# USERBUILD is a list of additional directories to remove when cleaning the project.
# EXTTOOL is an optional command executed before processing audio, graphics and code files.
#
# All directories are specified relative to the project directory where the makefile is found.
#---------------------------------------------------------------------------------------------------------------------
TARGET      	:=  Work_Life_jam
BUILD       	:=  build
LIBBUTANO   	:=  ../butano
PYTHON      	:=  python
SOURCES     	:=  src ../common/src
INCLUDES    	:=  include ../common/include
DATA        	:=
GRAPHICS    	:=  graphics ../common/graphics
AUDIO       	:=  audio ../common/audio
DMGAUDIO    	:=  dmg_audio
ROMTITLE    	:=  WORKLIFE24
ROMCODE     	:=  SBTP
# USERFLAGS   	:=  -DBN_CFG_AUDIO_MIXING_RATE=BN_AUDIO_MIXING_RATE_16_KHZ
USERFLAGS   	:=  -DBN_CFG_AUDIO_MIXING_RATE=BN_AUDIO_MIXING_RATE_27_KHZ
# USERFLAGS   	:=  -DBN_CFG_AUDIO_MIXING_RATE=BN_AUDIO_MIXING_RATE_31_KHZ
USERCXXFLAGS	:=  
USERASFLAGS 	:=  
USERLDFLAGS 	:=  
USERLIBDIRS 	:=  
USERLIBS    	:=  
DEFAULTLIBS 	:=  true
STACKTRACE		:=	
USERBUILD   	:=  
EXTTOOL     	:=  

#---------------------------------------------------------------------------------------------------------------------
# Export absolute butano path:
#---------------------------------------------------------------------------------------------------------------------
ifndef LIBBUTANOABS
	export LIBBUTANOABS	:=	$(realpath $(LIBBUTANO))
endif

#---------------------------------------------------------------------------------------------------------------------
# Include main makefile:
#---------------------------------------------------------------------------------------------------------------------
include $(LIBBUTANOABS)/butano.mak

clean_music:
	rm ./audio/*.wav

music-empty:
	python ./audio/audio.py -e -i ./audio/kevin_macleod_airport_lounge.mp3

AUDIO_SOURCE=./audio/source/kevin_macleod_airport_lounge.mp3

music-real:
	cp ./audio/source/kevin-macleod-airport-lounge.mp3 ${AUDIO_SOURCE}

music:
	python ./audio/audio.py --mp3_to_wav -i ${AUDIO_SOURCE}
	python ./audio/audio.py --wav_slice -ss 00:00:00.00 -se 00:00:29.50 -i ${AUDIO_SOURCE} --out_prefix ./audio/jazz_monday.wav
	python ./audio/audio.py --wav_slice -ss 00:00:35.75 -se 00:00:59.75 -i ${AUDIO_SOURCE} --out_prefix ./audio/jazz_tuesday.wav
	python ./audio/audio.py --wav_slice -ss 00:01:01.50 -se 00:01:20.00 -i ${AUDIO_SOURCE} --out_prefix ./audio/jazz_wednesday.wav
	python ./audio/audio.py --wav_slice -ss 00:02:04.50 -se 00:02:26.50 -i ${AUDIO_SOURCE} --out_prefix ./audio/jazz_thursday.wav
	python ./audio/audio.py --wav_slice -ss 00:02:27.50 -se 00:02:57.00 -i ${AUDIO_SOURCE} --out_prefix ./audio/jazz_friday.wav
	python ./audio/audio.py --wav_slice -ss 00:03:04.25 -se 00:03:48.50 -i ${AUDIO_SOURCE} --out_prefix ./audio/jazz_saturday.wav
	python ./audio/audio.py --wav_slice -ss 00:04:54.00 -se 00:05:07.25 -i ${AUDIO_SOURCE} --out_prefix ./audio/jazz_day_end.wav
	python ./audio/audio.py --wav_to_chunked -i ./audio/jazz_monday.wav --out_prefix ./audio/jazz_monday
	python ./audio/audio.py --wav_to_chunked -i ./audio/jazz_tuesday.wav --out_prefix ./audio/jazz_tuesday
	python ./audio/audio.py --wav_to_chunked -i ./audio/jazz_wednesday.wav --out_prefix ./audio/jazz_wednesday
	python ./audio/audio.py --wav_to_chunked -i ./audio/jazz_thursday.wav --out_prefix ./audio/jazz_thursday
	python ./audio/audio.py --wav_to_chunked -i ./audio/jazz_friday.wav --out_prefix ./audio/jazz_friday
	python ./audio/audio.py --wav_to_chunked -i ./audio/jazz_saturday.wav --out_prefix ./audio/jazz_saturday
	python ./audio/audio.py --wav_to_chunked -i ./audio/jazz_day_end.wav --out_prefix ./audio/jazz_day_end
	# python ./audio/audio.py -x -i ./audio/kevin_macleod_airport_lounge.wav --out_prefix ./audio/comp
	# python ./audio/audio.py -c -i ./audio/comp_kevin_macleod_airport_lounge.wav --out_prefix ./audio/jazz_1
	rm ./audio/jazz_monday.wav
	rm ./audio/jazz_tuesday.wav
	rm ./audio/jazz_wednesday.wav
	rm ./audio/jazz_thursday.wav
	rm ./audio/jazz_friday.wav
	rm ./audio/jazz_saturday.wav
	rm ./audio/jazz_day_end.wav
	# rm ./audio/comp_kevin_macleod_airport_lounge.wav

launch:
	"C:\Program Files\mGBA\mGBA.exe" ./$(TARGET).gba

build/wasm:
	git clone --single-branch --depth 1 https://github.com/jgensler8/44vba-wasm ./build/wasm

wasm: $(TARGET).gba build/wasm
	sed -i "s/vn-game.gba/Work_Life_jam.gba/g" ./build/wasm/app.js
	cp $(TARGET).gba ./build/wasm
	sed -i "s/background-color: #000000/background-color: #dcdcdc/g" ./build/wasm/index.html
	# tar -a -c --directory build/wasm -f Work_Life_jam_wasm.zip .
	powershell -command "cd build/wasm; Compress-Archive -Force * ../Work_Life_jam_wasm.zip"


wc:
	grep -h -e "MC(" -e "INO(" -e "KANADE(" -e "RIKA(" -e "RIN(" -r ./src | wc
	grep -h -e "MC(" -r ./src | wc
	grep -h -e "INO(" -r ./src | wc
	grep -h -e "KANADE(" -r ./src | wc
	grep -h -e "RIKA(" -r ./src | wc
	grep -h -e "RIN(" -r ./src | wc
	grep -h -e "EMPTY(" -r ./src | wc
	grep -h \
		-e "INO_TEXT(" -e "KANADE_TEXT(" -e "RIKA_TEXT(" -e "RIN_TEXT(" \
		-e "INOS_FATHER(" -e "INOS_MOTHER(" -e "RUDOLPH(" -e "ORAGANIZER" \
		-e "KANADES_MOTHER(" -e "KANADES_FATHER(" -e "KANADES_BROTHER(" \
		-e "COOKING_INSTRUCTIONS(" -e "WAREHOUSE_SUPERVISOR(" -e "WAREHOUSE_TEAM_LEAD" -e "WAREHOUSE_INSTRUCTIONS" \
		-e "GARDENING_INSTRUCTIONS(" -e "ORGANIZER(" \
		-e "TEAM_CAPTAIN(" \
		-e "STELLA(" -e "IRENE(" \
		-r ./src | wc