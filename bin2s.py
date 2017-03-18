import sys, getopt, ntpath, os


def print_help():
    print("Usage: python bin2s.py -i infile -o outfile [-s symbol]")

def main(argv):
    try:
        opts, args = getopt.getopt(argv, "hi:o:s:", ["help"])
    except getopt.GetoptError:
        sys.exit(2)
    infile = None
    outfile = None
    sym = None
    #Parse the options
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print_help()
            sys.exit(0)
        if opt == "-i":
            infile = arg
        if opt == "-o":
            outfile = arg
        if opt == "-s":
            sym = arg
        
    if not sym:
        sym = os.path.splitext(os.path.basename(outfile))[0]

    #Open the f
    fd_in = open(infile, "rb")
    content = [str(hex(byte)) for byte in bytearray(fd_in.read())]
    fd_in.close()

    #Create an outputfile
    ocontent = ".align 4\n.global "+sym+"\n\n@//***RAW DATA FROM "+infile+"***\n\n"+sym+":\n.byte "+",".join(content)+"\n"

    #Write output
    fd_out = open(outfile, "w+")
    fd_out.write(ocontent)
    fd_out.close()

if __name__ == "__main__":
    main(sys.argv[1:])
