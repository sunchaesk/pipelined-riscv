#!/usr/bin/perl
use strict;
use warnings;

# File containing the simulator output
my $input_file = './test/simulator_output.txt';

# Output files
my $register_file = './test/registers.txt';
my $memory_file   = './test/memory.txt';

# Open the input file for reading
open my $fh, '<', $input_file or die "Cannot open '$input_file': $!";

# Open output files for writing
open my $reg_fh, '>', $register_file or die "Cannot open '$register_file': $!";
open my $mem_fh, '>', $memory_file   or die "Cannot open '$memory_file': $!";

while ( my $line = <$fh> ) {
    chomp $line;

    # Check if the line starts with 'x' (register values)
    if ( $line =~ /^x(\d+)\s+0x([0-9a-fA-F]{8})/ ) {
        my $reg_num = $1;
        my $reg_val = $2;
        print $reg_fh "$reg_val\n";
    }

    # Check if the line starts with 'Mem[' (memory values)
    elsif ( $line =~ /^Mem\[0x[0-9a-fA-F]+\]\s*(.*)$/ ) {
        my $mem_values = $1;
        my @values = split /\s+/, $mem_values;  # Split the values by whitespace

        foreach my $value (@values) {
            $value =~ s/^0x//;                  # remove the 0x prefix
            print $mem_fh "$value\n";           # Print each value on a new line
        }
    }
}

# Close all file handles
close $fh;
close $reg_fh;
close $mem_fh;

print
  "Parsing completed. Check '$register_file' and '$memory_file' for results.\n";
