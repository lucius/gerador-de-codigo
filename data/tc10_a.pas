program tc10_a();
var a,b,c,d,e:integer;

function f01(p01:integer):integer;
	function f02(p02:integer):integer;
		function f03(p03:integer):integer;
			function f04(p04:integer):integer;
				function f05(p05:integer):integer;
				begin
					f05:=f06(06)
				end
			begin
				f04:=f05(05)
			end
		begin
			f03:=f04(04)
		end
	begin
		f02:=f03(03)
	end
begin
	f01:=f02(02)
end
begin
	write (f01(0))
end.