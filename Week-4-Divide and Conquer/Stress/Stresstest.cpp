while(true)
    {
       int n= rand() % 100 + 2; 
       cout<<n<<"\n";
       vector<point> a;
       point arr[n];
       for(int i=0;i<n;i++)
       {
           a[i].x=(rand() % 100000);
           a[i].y=(rand() % 100000);
       }
       for(int i=0;i<n;i++)
       {
           arr[i]=a[i];
       }
       for(int i=0;i<n;i++)
       {
           cout<<"("<<arr[i].x<<','<<arr[i].y<<")"<<" "; 
       }
       cout<<"\n";
       double res1=bruteforce(arr,n);
       double res2=CloseDist(arr,0,n-1);
       if(res2==res1)
       {
           cout<<"OK\n";
       }
       else
       {
           cout<<"Wrong Answer"<<res1<<' '<<res2<<"\n";
           break;
       }
    }