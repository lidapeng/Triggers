#pragma once
#include <string>
using namespace std;

class CParams
{
public:
	CParams(void);
	~CParams(void);
	int readParams(string strFile);
	string getInFile(){return m_inFile;}
	string getNetFile(){return m_netFile;}
	string getOFile(){return m_oFile;}
	string getCellFile(){return m_cellFile;}
	string getUFile(){return m_uFile;}
	string getTrigFile(){return m_trigFile;}
	int getTime(){return m_time;}
	int getCellID(){return m_cell;}
private:
	string m_inFile;
	string m_netFile;
	string m_oFile;
	string m_cellFile;
	string m_uFile;
	string m_trigFile;
	int m_time;
	int m_cell;
};

