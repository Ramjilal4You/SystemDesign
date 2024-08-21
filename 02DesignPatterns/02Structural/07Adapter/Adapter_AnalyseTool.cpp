/*
XMLData class - Adaptee
DataAnalyticsTool - target
Adapter
Client
*/

#include <string>
#include <iostream>
using namespace std;

class JSONData{
    string jsondata;
public:
    JSONData(string pJsonData):jsondata(pJsonData){}
    string getJsonData(){return jsondata;}
};

//Adaptee (Legacy)
class XMLData{
    string xmldata;
public:
    XMLData(string pXmlData):xmldata(pXmlData){}
    string getXmlData(){return xmldata;}
};

//target
class DataAnalyticsTool{
    JSONData *jSonData;
public:
    DataAnalyticsTool(){cout<<"DataAnalyticsTool()\n";}
    DataAnalyticsTool(JSONData *pJsonData):jSonData(pJsonData){
        cout<<"DataAnalyticsTool(JSONData *pJsonData)\n";
    }
    virtual void  Analyse(){
        cout<<"DataAnalytics Tool is Analysing the "<<jSonData->getJsonData()<<"\n\n";
    }
};
class Adapter : public DataAnalyticsTool{
    XMLData *xmldata;
public:
    Adapter(XMLData *pXmlData):xmldata(pXmlData){
        cout<<"Adapter(XMLData *pXmlData)\n";
    }
    void  Analyse(){
        cout<<"Converting the "<<xmldata->getXmlData()<<" to Json Data\n";

        JSONData *jsonData = new JSONData(xmldata->getXmlData()+" as JSon Data");
        
        DataAnalyticsTool *pTool = new DataAnalyticsTool(jsonData);
        pTool->Analyse();
    }
};

//client Code
int main(){
    XMLData *xml = new XMLData("XML Data");
    //DataAnalyticsTool *pTool = new DataAnalyticsTool(xml);
    DataAnalyticsTool *pTool = new Adapter(xml);
    pTool->Analyse();

return 0;
}