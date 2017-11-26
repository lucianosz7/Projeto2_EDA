typedef union _Info 
{
	unsigned long value;
	unsigned char bytes[4];
} Info;

unsigned long 
hash_enlacamento_deslocado(const char *text)
{
	int size, i, h;
	Info info;
	
	size = strlen(text);
	h = 0;
	
	for (i = 0, info.value = 0; i < 4 
		&& i < size; i++)
	{
		info.bytes[i] = text[i];
	}
	
	h = info.value;
	
	for (i = 4, info.value = 0; i < size; i++)
	{
		info.bytes[i % 4] = text[i];
		
		if (i % 4 == 3)
		{
			h ^= info.value;
			info.value = 0;
		}
	}
	
	return h;
}