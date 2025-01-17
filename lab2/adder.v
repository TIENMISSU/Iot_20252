`timescale 1ns/10ps
module adder
	#(parameter DW = `DATA_WIDTH)
	(input [DW-1:0] A,
	 input [DW-1:0] B,
	 output [2*DW+1:0] C)
;

	assign C = (A + B) * (A - B);
endmodule

module tb;
	parameter DW = `DATA_WIDTH;
	reg [DW-1:0] a, b;
	wire [2*DW+1:0] c;
	reg clk;

	initial begin
		clk = 0;
		repeat (50)
			#10 clk = ~clk;
	end

	adder dut (.A(a),.B(b),.C(c));

	initial begin
		$dumpfile("wave.vcd");
		$dumpvars(0, tb, dut);
		a = 1;
		b = 2;
		#10;
		a = 2;
		b = 4;
		#20;
		a = 3;
		b = 5;
		#10;
		//$finish();
	end
endmodule
