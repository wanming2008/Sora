/*+--------------------------------------------------------------------------
Copyright (c) 2015, Microsoft Corporation 
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------*/

`timescale 1ns / 1ps

module RCB_FRL_count_to_128(
		input	clk, 
		input	rst, 
		input	count, 
		input	ud, 
		output reg [6:0]	counter_value
	);

//This module counts up/down between 0 to 128

//input clk, rst, count, ud;
//output [6:0] counter_value;

wire [6:0] counter_value_preserver;
//reg [6:0] counter_value/*synthesis syn_noprune = 1*/;

always@(posedge clk or posedge rst)	begin
	if(rst == 1'b1)
		counter_value = 7'h00;
	else begin
	  case({count,ud})
			2'b00: counter_value = 7'h00;
			2'b01: counter_value = counter_value_preserver;
			2'b10: counter_value = counter_value_preserver - 1;
			2'b11: counter_value = counter_value_preserver + 1;
			default: counter_value = 7'h00;
	  endcase
	end
end

assign counter_value_preserver = counter_value;

endmodule	
