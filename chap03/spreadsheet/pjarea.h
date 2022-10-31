//pjarea.h
#ifndef PJAREA_H
#define PJAREA_H

#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <float.h>
#include <exception>
#include "common.h"
#include "country.h"

using column = country; //给国家起个别名列
using MyCell = twolevel;

class pjarea
{
public:
    pjarea(string& areaName):m_name(areaName) {;}
    pjarea():m_name("unkown area") {;}

public:
    //get
    string getAreaName(){return m_name;}
    int    getCountryNum(){return m_mapCountry.size();}
    //整个区域的原始数据是否已经准备好
    bool   isReady() {
        map<int,country*>::const_iterator it;
        for(it=m_mapCountry.begin();it!=m_mapCountry.end();++it) {
            if (!it->second->isReady()) {
                return false;
            }
        }
        return true;
    }
    bool isParseOk() {
        return true; //这里要校验所有的分析结果是否ok
    }

    //注意:这个函数会返回空指针
    country* getCountry(int countryID)
    {
        /*
        if(countryID<eCountryID::c0 && countryID>=m_mapCountry.size()) {
            throw std::runtime_error("failed to get countryID");
        }*/
        if(m_mapCountry.count(countryID)>0) {
            return m_mapCountry[countryID];
        } else {
            return NULL;
        }
    }



private:
    //取最小最大值
    void getMinMax(vector<float> vectFloat,float& min, float& max) {
        max = FLT_MIN;
        min = FLT_MAX;
        for(unsigned int i=0;i<vectFloat.size();++i) {
            if(max<vectFloat[i]) {
                max = vectFloat[i];
            }
            if(min>vectFloat[i]) {
                min = vectFloat[i];
            }
        }
    }

    //计算标准差
    float standardDeviation(vector<float> list ){
        int n = list.size();
        double sigma = 0, pSigma = 0;
        for (int i = 0; i < n; ++i) {
            float v = list.at(i);
            sigma += v;        // sum
            pSigma += v*v;     // 平方和
        }
        sigma /= list.size();          // 获得平均值
        return sqrt((pSigma/n - sigma*sigma)) ;
    }


public:
    //set
    void setCountry(country* curCountry) {

        if(!curCountry->isReady()) {
            throw std::runtime_error("the country or column is not ready");
        }
        if( m_mapCountry.count(curCountry->getCountryID())>=0) {
            delete m_mapCountry[curCountry->getCountryID()]; //delete旧的country
        }
        m_mapCountry[curCountry->getCountryID()] = curCountry;
    }

public:
    //分析
    void debugParse();
    void debugOriData();

private:
    void debugGYH();
    void debugResult();
    void debugOther();

protected:
    string m_name; //区域名称
    map<int,country*> m_mapCountry; //对应的原始数据国家,国家ID从0开始

    //对应的归一化后的结果
    map<int,country*> m_mapCountryGYH;
    //对应的最后结果
    map<int,country*> m_mapCountryResult;
    //标准差结果
    column* m_bzcOneResult;
    //重要性之比前驱值
    column* m_preOneZYX;
    //重要性之比
    column* m_oneZYX;
    //指标权重
    column* m_onePower;
    //准则层标准差
    column* m_bzcTwoResult;
    //准则层重要性之比前驱
    column* m_preTwoZYX;
    //准则层重要性之比
    column* m_twoZYX;
    //准则层权重
    column* m_twoPower;
    //指标的全局权重
    column* m_allPower;
    //全局其他信息
    column* m_other;
};

//数据分析过程
/*
void pjarea::parse() {
    if(!this->isReady()) {
        throw std::runtime_error("the pjarea is not ready");
    }

    //1.归一化处理
    map<int,country>::iterator it;
    map<int,float> mapGYH;
    int oneLevel=tlevel::t1;
    for(it=m_mapCountry.begin();it!=m_mapCountry.end();++it) {
        onelevel curOneLevel = it->second.getOneLevel(oneLevel);
        for(int twoLevel=tlevel::t1;twoLevel<=curOneLevel.getTwoLevelNum();++twoLevel) {

        }
        ++oneLevel;
    }

    float min(0);
    float max(0);
    for(int countryID=0;countryID<m_countryNum;++countryID) {


    }


    //1.标准化

}*/
#endif // PJAREA_H
