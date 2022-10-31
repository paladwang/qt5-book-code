#ifndef COUNTRY_H
#define COUNTRY_H
#include "common.h"
#include "twolevel.h"
#include "onelevel.h"

class country {
private:
    string  m_name; // 国家或列名称
    int m_countryid; //国家ID
    map<int,onelevel*> m_mapOneLevel;
public:
    country(string& name,unsigned countryID):m_name(name),m_countryid(countryID){;}
    country(char* name,unsigned countryID):m_name(name),m_countryid(countryID){;}
    country():m_name("default country"),m_countryid(eCountryID::nocountry) {;}
    country(country& c) {
        m_name = c.m_name;
        m_countryid = c.m_countryid;
        map<int,onelevel*>::iterator it;
        for(it=c.m_mapOneLevel.begin();it!=c.m_mapOneLevel.end();++it) {
            onelevel* oneLevel = new onelevel(*(it->second));
            m_mapOneLevel[oneLevel->getLevelID()] = oneLevel;
        }
    }

public:
    string getName() {return m_name;}
    unsigned getCountryID() {return m_countryid;}
    bool isReady() {
        map<int,onelevel*>::iterator it;
        for(it=m_mapOneLevel.begin();it!=m_mapOneLevel.end();++it) {
            if (!it->second->isReady()) {
                return false;
            }
        }
        if (m_countryid<=eCountryID::nocountry) {
            return false;
        }
        return true;
    }
    map<int,onelevel*>::const_iterator begin() {return m_mapOneLevel.begin();}
    map<int,onelevel*>::const_iterator end() { return m_mapOneLevel.end();}
public:
    void setOneLevel(onelevel* oneLevel) {
        if(!oneLevel->isReady()) {
            throw std::runtime_error("the onelevel is not ready");
        }
        if( m_mapOneLevel.count(oneLevel->getLevelID())>0 ) {
            delete m_mapOneLevel[oneLevel->getLevelID()]; //delete就的onelevel
        }
        m_mapOneLevel[oneLevel->getLevelID()] = oneLevel;
    }
};

#endif // COUNTRY_H
