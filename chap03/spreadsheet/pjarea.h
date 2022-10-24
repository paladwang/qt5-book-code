//pjarea.h
#ifndef PJAREA_H
#define PJAREA_H

#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <float.h>
#include <exception>

using std::string;
using std::vector;
using std::map;
using std::exception;
using std::runtime_error;

//指标的级别
enum tlevel {unkown=0,t1=1,t2,t3,t4,t5,t6,t7};

//二级指标定义
class twolevel {
public:
    twolevel(string name, int level, float value, bool isPositive) {
        m_name=name;
        m_levelid=level;
        m_isPositive=isPositive;
        m_value = value;
    }
private:
    twolevel(){;} //禁止默认构造函数

public:
    string getName(){return m_name;}
    int    getLevel(){return m_levelid;}
    bool   isPositive(){return m_isPositive;}
    float  getValue(){return m_value;}
    virtual bool isReady() {
        if (m_levelid>=tlevel::t1 && m_levelid<=tlevel::t7) {
            return true;
        } else {
            return false;
        }
    }

protected:
    string m_name;
    int    m_levelid; //指标ID
    bool   m_isPositive; //true-正向指标,false-负向指标
    float  m_value; //指标值
};

class myCell : twolevel {
public:
    myCell(int level,float value) {
        m_levelid = level;
        m_value = value;
        m_isPositive = true; //对应cell来说没意义
        m_name = ""; //这里不用了
    }
private:
    myCell(){;} //禁止默认构造函数
};

//7个一级指标,每个一级指标4-7个二级指标
//一级指标定义
class onelevel {
public:
    onelevel(string name,int levelid,int twolevelnum) {
        m_name=name;
        m_levelid=levelid;
        m_twolevelNum=twolevelnum;
    }

private:
    onelevel(){;} //禁止默认构造函数

public:
    //get
    string getName(){return m_name;}
    int    getLevel(){return m_levelid;}
    int    getTwoLevelNum(){return m_twolevelNum;}
    bool   isReady() {
        if (m_twolevelNum==m_mapTwoLevel.size()) {
            //取已有two_level里的最大ID
            int levelid_max = 0;
            map<int,twolevel>::iterator it;
            for(it=m_mapTwoLevel.begin();it!=m_mapTwoLevel.end(); ++it) {
                if (it->first>levelid_max) {
                    levelid_max = it->first;
                }
            }
            if ((levelid_max-tlevel::t1+1)==m_twolevelNum) {
                return true;
            }
        }
        return false;
    }

    twolevel getTwoLevel(int tlevel) {
        if (m_mapTwoLevel.count(tlevel)>0) {
            return m_mapTwoLevel[tlevel];
        } else {
            throw std::runtime_error("the twolevel does not exist");
        }
    }

public:
    //set
    void setTwoLevel(twolevel curTwoLevel) {
        if (!curTwoLevel.isReady()) {
            throw std::runtime_error("the twolevel is not ready");
        }
        m_mapTwoLevel[curTwoLevel.getLevel()]=curTwoLevel;
    }

protected:
    string m_name; //一级指标名称
    int    m_levelid; //一级指标ID
    int    m_twolevelNum; //这个一级指标的二级指标个数
    map<int,twolevel> m_mapTwoLevel; //对应的二级指标个数
};

//一个国家的所有指标
class country {
public:
    country(string name,int countryId,int onelevelnum=7) {
        m_name=name;
        m_countryId = countryId;
        m_onelevelNum=onelevelnum;
        m_mapOneLevel.clear();
    }

private:
    country(){;} //禁止默认构造函数

public:
    //get
    string getName(){return m_name;}
    int    getCountryId() { return m_countryId;}
    int    getOneLevelNum(){return m_onelevelNum;}
    //所以的指标值是否已经就绪
    bool   isReady() {
        int readyNum = 0;
        int levelid_max = 0;
        map<int,onelevel>::iterator it;
        for(it=m_mapOneLevel.begin(); it!=m_mapOneLevel.end(); ++it) {
            if (it->second.isReady()) {
                readyNum++;
            }
            if (it->first>levelid_max) {
                levelid_max = it->first;
            }
        }
        if (m_onelevelNum==readyNum && ((levelid_max-tlevel::t1+1)==m_onelevelNum)) {
            return true;
        }
        return false;
    }

    //取一级指标
    onelevel getOneLevel(int tlevel) {
        if (m_mapOneLevel.count(tlevel)>0) {
            return m_mapOneLevel[tlevel];
        } else {
            throw std::runtime_error("the onelevel does not exist");
        }
    }

    //直接取二级指标
    twolevel getTwoLevel(int t_onelevel,int t_twolevel) {
        return getOneLevel(t_onelevel).getTwoLevel(t_twolevel);
    }

public:
    //set
    void setOneLevel(onelevel curOneLevel) {
        if (!curOneLevel.isReady()) {
            throw std::runtime_error("the onelevel is not ready");
        }
        m_mapOneLevel[curOneLevel.getLevel()]=curOneLevel;
    }

protected:
    string m_name; //国家名称
    int    m_countryId; //国家ID
    int    m_onelevelNum; //一个国家的一级指标个数(固定值7)
    map<int,onelevel> m_mapOneLevel; //对应的一级指标
};

using column = country; //给国家起个别名列

class pjarea
{
public:
    pjarea(string& areaName,int countryNum) {
        m_name = areaName;
        m_countryNum = countryNum;
        m_mapCountry.clear();
    }
private:
    pjarea();

public:
    //get
    string getAreaName(){return m_name;}
    int    getCountryNum(){return m_countryNum;}
    //整个区域的原始数据是否已经准备好
    bool   isReady() {
        map<int,country>::iterator it;
        for(it=m_mapCountry.begin();it!=m_mapCountry.end();++it) {
            if (!it->second.isReady()) {
                return false;
            }
        }

        return true;
    }

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

public:
    //set
    void setCountry(country curCountry) {
        m_mapCountry[curCountry.getCountryId()]=curCountry;
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
    //分析
    void debugParse();
    void debugOriData();

private:
    void debugGYH();
    void debugResult();
    void debugOther();

protected:
    string m_name; //区域名称
    int    m_countryNum; //国家个数
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

//数据分析过程-debug版本
void pjarea::debugParse() {
    if(!this->isReady()) {
        throw std::runtime_error("the pjarea is not ready");
    }
    debugGYH(); //归一化debug数据
    debugResult(); //result数据
}

#endif // PJAREA_H
