#include "params.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>

CParams::CParams(void)
{
	m_inFile = "";
	m_netFile = "";
	m_oFile = "";
	m_cellFile = "";
	m_uFile = "";
	m_trigFile = "";
	m_time = 0;
	m_cell = -1;
}


CParams::~CParams(void)
{
}

int CParams::readParams(string strFile){
	ifstream inFile(strFile.c_str());
	int nRowCount = 0;
	
	//cout<<strFile<<endl;
	try
	{
		if (inFile.is_open())
		{
			string strLine = "";
			cout<<"reading params file"<<endl;
			inFile.seekg(0,fstream::end);
			ifstream::pos_type end_mark = inFile.tellg();
			inFile.seekg(0,fstream::beg);

			while(inFile && inFile.tellg()!=end_mark && getline(inFile,strLine))
			{
				istringstream iss(strLine);
				string strTemp;
				switch (nRowCount)	
				{
				case 0:
					cout<<strLine<<endl;
					break;
				case 1:
					cout<<strLine<<endl;
					break;
				case 2:
					cout<<strLine<<endl;
					
					//m_inFile = strLine.substr(strLine.find('\t'));
					iss>>strTemp>>m_inFile;
					//cout<<m_inFile<<endl;
					break;
				case 3:
					cout<<strLine<<endl;
					iss>>strTemp>>m_netFile;
					break;
				case 4:
					cout<<strLine<<endl;
					iss>>strTemp>>m_oFile;
					break;
				case 5:
					cout<<strLine<<endl;
					iss>>strTemp>>m_cellFile;
					break;
				case 6:
					cout<<strLine<<endl;
					iss>>strTemp>>m_uFile;
					break;
				case 7:
					cout<<strLine<<endl;
					iss>>strTemp>>m_trigFile;
					break;
				case 8:
					cout<<strLine<<endl;
					iss>>strTemp>>m_time;
					break;
				case 9:
					cout<<strLine<<endl;
					iss>>strTemp>>m_cell;
					break;
				default:
					break;
				}


				//if (0 == nRowCount)
				//{
				//	if (!(iss>>strTemp))
				//	{
				//		return 1;
				//	}

				//	cout<<strLine<<endl;

				//}
				nRowCount++;
			}
			inFile.close();

			m_cell = m_cell -1;

			cout<<"Reading WUIVAC configuration file: "<<strFile<<" done"<<endl;
		}
		else
		{
			cout<<"open file failed"<<endl;
			return 1;
		}
	}

	catch (exception &e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}

	return 0;

}