int hash_soma(const char *text)
{
	const char *p;
	int h;
	
	if (!text)
		return 0;
	
	for (p = text, h = 0; *p; p++)
		h += *p;
	
	return h;
}
