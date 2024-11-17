int func()
{
	int ar[] = { 1, 3, 5, 7 };

	//return ar [[]{return 1; }()]; //error
	//return ar [ []{return 1; }()]; //still error
	return ar[([] {return 1; }())]; //valid
}

