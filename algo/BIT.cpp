/*
 *  BIT.cpp
 */

const int max_n = 100000;

int BIT[max_n];

void update(int incr, int idx)		// increments "array value" at position idx by "incr"
{
	int pos = idx;
	while(pos < max_n)
	{
		BIT[pos] += incr;
		pos += pos & (-pos);
	}
}

int query(int idx)					// finds "prefix sum" of elements from 1 to idx.
{
	int pos = idx;
	int sum = 0;
	while(pos > 0)
	{
		sum += BIT[pos];
		pos -= pos & (-pos);
	}
	return sum;
}

int main()
{
	for(int i = 0; i < max_n; i++)
		BIT[i] = 0;
}
