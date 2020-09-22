bool Check(int N,int pos) {
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
vector<int> bitwise_sieve(int n)
{
     vector<int> primes ;
     int status[n/32+5];
     for( int i = 3; i*i <= n; i += 2 ) 
	     if( !Check(status[i/32],i%32)) {
	 	     for( int j = i*i; j <= n; j += 2*i )
			     status[j/32]=Set(status[j/32],j % 32);
		 }

	 primes.PB(2);
	 for(int i=3;i<=n;i+=2) if(!Check(status[i/32],i%32)) primes.PB(i);
     return primes ;
}
