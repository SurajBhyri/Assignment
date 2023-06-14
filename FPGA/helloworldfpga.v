module helloworldfpga(
    output wire nD2,
    output wire nD1,
    output wire nD0,
    output wire c
);
    wire clk;

    qlal4s3b_cell_macro u_qlal4s3b_cell_macro (
        .Sys_Clk0 (clk),
    );

    reg[26:0] delay;
     reg	d0;
     reg	d1;
     reg	d2;
always@(posedge clk) begin
delay = delay+1; 

if(delay > 20000000) 
begin
delay=27'b0;
nD2 = ((d2&d0)|(d1&(!d0)));
nD1 = (((!d2)&d0)|(d1&(!d0)));
nD0 = ((!d2)&(!d1))|(d2&d1);
d2 = nD2;
d1 = nD1;
d0 = nD0;
end
end
assign c = clk;
endmodule


