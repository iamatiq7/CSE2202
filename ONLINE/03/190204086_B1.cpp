#include<bits/stdc++.h>
using namespace std;

int degree;

float applyHorners(int poly[], float x)
{

    float result = poly[0];

    for(int i=1;i<=degree;i++)
        result = poly[i] + result*x;

    return result;
}


void modifiedBisection(int poly[], float initialApprox1, float initialApprox2, float interval)
{
    float f1,f2,root,froot;

    int c=0;

    float x1 = initialApprox1;
    float x2 = x1 + interval;

    while(x1<initialApprox2)
    {
         f1 = applyHorners(poly, x1);
         f2 = applyHorners(poly, x2);

        if((f1*f2)>0)
        {
            x1 = x2;
            x2 = x1+interval;
            continue;
        }
        else{
            c++;
            do{

                f1 = applyHorners(poly, x1);
                f2 = applyHorners(poly, x2);

                root = (x1+x2)/2;
                froot = applyHorners(poly, root);


                if((f1*froot)<0)
                    x2 = root;
                else
                    x1 = root;


            }
            while(froot>=0.0001);

            if(c<4)
                cout<<initialApprox1<<"-"<<initialApprox2<<"               "<<c<<"                "<<root<<endl;
            else
            {
                cout<<"Maximum number of roots already found"<<endl;

                for(int i=0;i<=degree;i++)
                    cout<<poly[i]<<" ";
                exit(0);
            }

        }

        x1 = x2;
        x2 = x1+interval;
    }

}


int main()
{

    float initialApprox1, initialApprox2, interval;

    cout<<"Enter the highest degree of the equation: ";
    cin>>degree;

    cout<<"Maximum number of roots are: "<<degree<<endl;

    int poly[degree+1];

    cout<<"Enter value of coefficients: "<<endl;

    for(int i=degree;i>=0;i--)
    {
        cout<<"Coefficient x"<<i<<" = ";
        cin>>poly[i];
        cout<<endl;
    }

    cout<<"Enter interval increment size: "<<endl;

    cin>>interval;


    reverse(poly, poly + degree+1);


    cout<<"Enter four sets of interval:"<<endl;


    for(int i=0;i<4;i++)
    {
        cin>>initialApprox1>>initialApprox2;


        cout<<"For interval size     "<<"No of root     "<<"Roots     "<<endl;


        modifiedBisection(poly, initialApprox1, initialApprox2, interval);


    }

    return 0;

}



