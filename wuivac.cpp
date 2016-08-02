#include <iostream>
#include "rasternet.h"
#include "params.h"
using namespace std;


void main(int argc, char* argv[])
{
	cout<<"Starting WUIVAC"<<endl;
	CParams params;

	if (argc<2)
	{
		cout<<argc<<endl;
		cout<<"Please enter the WUIVAC parameter configuration file"<<endl;
		exit(0);
	}
	else
	{
		cout<<"Reading WUIVAC configuration file: "<<argv[1]<<endl;
		
		params.readParams(string(argv[1]));
		//cout<<"cellFile: "<<params.getCellFile()<<endl;
		//cout<<"cellFile: "<<params.getCellFile().size()<<endl;
	}
	

	CRasterNet rasterNet;


	rasterNet.readROSRasterData(params.getInFile());
	rasterNet.createRasterNetwork();

	int cellID = params.getCellID();

	cout<<"\nDjkstra"<<endl;
	//rasterNet.Dijkstra(cellID,params.getTime());
	if (params.getCellFile()=="")
	{
		cout<<"No cell file\n";
	}
	else
	{
		cout<<"Cell file exists: "<<params.getCellFile()<<endl;
		rasterNet.readCellFile(params.getCellFile());
	}

	//rasterNet.Dijkstra(5050,1);
	rasterNet.calculateTriggerBufer(params.getCellID(),params.getTime());
	rasterNet.writeTriggerBuffer(params.getTrigFile());

	
	ifstream f(params.getTrigFile());
	vector<int> data;
	if (f.is_open())
	{
		while (f)
		{
			int b = -1;
			f>>b;
			data.push_back(b);
		}

	}
	f.close();
	int n =0;
	for (int i =0;i<data.size();i++)
	{
		if (data[i]==1)
		{
			//cout<<"node: "<<i<<endl;
			n++;
		}

	}
	cout<<"Total number of cells in the trigger buffer: "<<n<<endl;

	//int a;
	//cin>>a;


}