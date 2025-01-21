`timescale 1ns/10ps
module adder
	(input [3:0] A,
	 input [3:0] B,
	 output [4:0] C)
;

	assign C = (A + B) * (A - B);
    always (clk)
        T1 = A + B;
    always (clk)
        T2 = A - B;
    always (clk)
        T3 = T1 * T2;
endmodule

module tb;
	reg [3:0] a, b;
	wire [4:0] c;
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
