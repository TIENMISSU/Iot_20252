all: compile run display
compile:
	iverilog -D DATA_WIDTH=8 adder.v
run:
	./a.out
display:
	gtkwave wave.vcd 
