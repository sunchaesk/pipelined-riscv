java -jar rars1_6.jar asm.txt dump .text dump.txt HexText mc CompactDataAtZero 0-1000

outputs the commands to the dump.txt, runs the simulation with the memory addresses starting at index 0, and prints the memory values from 0 - 1000


Usage:  Rars  [options] filename [additional filenames]
  Valid options (not case sensitive, separate by spaces) are:
      a  -- assemble only, do not simulate
  ae<n>  -- terminate RARS with integer exit code <n> if an assemble error occurs.
  ascii  -- display memory or register contents interpreted as ASCII codes.
      b  -- brief - do not display register/memory address along with contents
      d  -- display RARS debugging statements
    dec  -- display memory or register contents in decimal.
   dump <segment> <format> <file> -- memory dump of specified memory segment
            in specified format to specified file.  Option may be repeated.
            Dump occurs at the end of simulation unless 'a' option is used.
            Segment and format are case-sensitive and possible values are:
            <segment> = .text, .data
            <format> = SegmentWindow, HexText, AsciiText, HEX, Binary, BinaryText
      h  -- display this help.  Use by itself with no filename.
    hex  -- display memory or register contents in hexadecimal (default)
     ic  -- display count of basic instructions 'executed'
     mc <config>  -- set memory configuration.  Argument <config> is
            case-sensitive and possible values are: Default for the default
            32-bit address space, CompactDataAtZero for a 32KB memory with
            data segment at address 0, or CompactTextAtZero for a 32KB
            memory with text segment at address 0.
     me  -- display RARS messages to standard err instead of standard out. 
            Can separate messages from program output using redirection
     nc  -- do not display copyright notice (for cleaner redirected/piped output).
     np  -- use of pseudo instructions and formats not permitted
      p  -- Project mode - assemble all files in the same directory as given file.
  se<n>  -- terminate RARS with integer exit code <n> if a simulation (run) error occurs.
     sm  -- start execution at statement with global label main, if defined
    smc  -- Self Modifying Code - Program can write and branch to either text or data segment
    rv64 -- Enables 64 bit assembly and executables (Not fully compatible with rv32)
    <n>  -- where <n> is an integer maximum count of steps to simulate.
            If 0, negative or not specified, there is no maximum.
 x<reg>  -- where <reg> is number or name (e.g. 5, t3, f10) of register whose 
            content to display at end of run.  Option may be repeated.
<reg_name>  -- where <reg_name> is name (e.g. t3, f10) of register whose
            content to display at end of run.  Option may be repeated. 
<m>-<n>  -- memory address range from <m> to <n> whose contents to
            display at end of run. <m> and <n> may be hex or decimal,
            must be on word boundary, <m> <= <n>.  Option may be repeated.
     pa  -- Program Arguments follow in a space-separated list.  This
            option must be placed AFTER ALL FILE NAMES, because everything
            that follows it is interpreted as a program argument to be
            made available to the program at runtime.
