//pjarea.h
#ifndef PJAREA_H
#define PJAREA_H

#include <string>
#include <vector>
#include <map>
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
    bool   isReady() {
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
    country(string name,int onelevelnum=7) {
        m_name=name;
        m_onelevelNum=onelevelnum;
        m_mapOneLevel.clear();
    }

private:
    country(){;} //禁止默认构造函数

public:
    //get
    string getName(){return m_name;}
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
    int    m_onelevelNum; //一个国家的一级指标个数(固定值7)
    map<int,onelevel> m_mapOneLevel; //对应的一级指标
};

class pjarea
{
public:
    pjarea();

};

#endif // PJAREA_H
