for (int j = 1; j < n; j+=2)
        {
            if(i==0)a[i][j]=x;
            else{
                if(j!=1&&i<k&&(j+1)%4==0)
                    a[i][j]=x;
                else if(j!=1&&(j+1)%4==0)a[i][j]=a[i-k][j];
                else a[i][j]=a[i-1][j];
            }
        }