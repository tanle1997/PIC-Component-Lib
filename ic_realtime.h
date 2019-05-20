// read time from ic 
// must declare hour, minute, second
void Read_time(unsigned char *hour, unsigned char *minute, unsigned char *second);
void Write_time(unsigned char hour, unsigned char minute, unsigned char second);
// must declare day, date, month, year
void Read_date(unsigned char *day, unsigned char *date, unsigned char *month, unsigned char *year);
void Write_date(unsigned char day, unsigned char date, unsigned char month, unsigned char year);
// convert BCD2DEC
unsigned char bcd2dec(unsigned char num);
//convert DEC2BCD
unsigned char dec2bcd(unsigned char num);

