extern "C"
{
	const char* losuvm_mark_(const char* file)
	{
		string _file = file;
		_mdfile = _file + ".md";
		_htmfile = _file+ ".htm"; 
		losumarkdown mk(_mdfile);
		mk.transferm();
		mk.html();
		return "1";
	}
}
