import mido
import fluidsynth
from mido.sockets import PortServer, connect

TCP_PORT = 5004
SOUNDFONT_PATH = "scripts/FluidR3_GM.sf2"
HOST = "localhost"
DRIVER = "coreaudio"


def play_midi(msg, fs):
    if msg.type == "note_on" and msg.velocity > 0:
        fs.noteon(0, msg.note, msg.velocity)
    elif msg.type == "note_off" or (msg.type == "note_on" and msg.velocity == 0):
        fs.noteoff(0, msg.note)


def main():
    fs = fluidsynth.Synth()
    fs.start(driver=DRIVER)
    sfid = fs.sfload(SOUNDFONT_PATH)
    fs.program_select(0, sfid, 0, 0)

    for message in connect(HOST, TCP_PORT):
        print(message)
        play_midi(message, fs)


if __name__ == "__main__":
    main()
