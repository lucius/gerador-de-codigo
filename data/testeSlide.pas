program ex();
var m: integer;
	function F(n:integer; var k:integer):integer;
	var p,q:integer;
	begin
		if n<2 then
		begin
			F:=n;
			k:=0
		end
		else
		begin
			F:=F(n-1,p)+F(n-2,q);
			k:=p+q+1
		end;
		write(n,k)
	end
begin
	write(F(3,m),m);
end.