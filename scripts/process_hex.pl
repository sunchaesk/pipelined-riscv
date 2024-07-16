#!/usr/bin/perl
use strict;

# Open the hex file for reading
my $input_file = $ARGV[0];
my $output_file = $ARGV[1];

open(my $fh, '<:raw', $input_file) or die "Cannot open file: $!";

# Read the entire file content
my $hex_content = do { local $/; <$fh> };

# Close the file handle
close($fh);

# Open output file
open(my $fh, '>', $output_file) or die "Could not open file '$output_file' $!";

# Remove the header and footer lines, and process the hex content
my @lines = split /\n/, $hex_content;

foreach my $line (@lines) {
    next if $line =~ /^\s*$/;  # Skip empty lines
    print $line;
    print "\n";
    # Remove leading hex address and trailing |...| sections
    $line =~ s/^\s*\w+\s+//; # Remove leading hex address
    $line =~ s/\s*\|.*$//;   # Remove trailing |...| section

    # Remove spaces and format to 8-digit groups
    my @line_list = split /\s+/, $line;
    my @line_list_1 = reverse @line_list[0..3];
    my @line_list_2 = reverse @line_list[4..7];
    my @line_list_3 = reverse @line_list[8..11];
    my @line_list_4 = reverse @line_list[12..15];
    
    my $line_1 = join "", @line_list_1;
    my $line_2 = join "", @line_list_2;
    my $line_3 = join "", @line_list_3;
    my $line_4 = join "", @line_list_4;

    print $fh $line_1;
    print $fh "\n";
    print $fh $line_2;
    print $fh "\n";
    print $fh $line_3;
    print $fh "\n";
    print $fh $line_4;
    print $fh "\n";
}

close $fh;

