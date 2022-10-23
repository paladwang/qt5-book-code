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

    //分析
    void parse();

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
void pjarea::parse() {
    if(!this->isReady()) {
        throw std::runtime_error("the pjarea is not ready");
    }
    int countryID = 0; //0-尼日利亚,1-安哥拉,2-刚果布,3-加蓬,4-喀麦隆

    //1.归一化数据-尼日利亚
    {
        country* pCountryGYH = new country("尼日利亚",countryID);
        m_mapCountryGYH[countryID] = pCountryGYH;

        //1-政治环境
        {
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.00,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.10,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.34,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.52,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,0.00,true);
            oneLevelOne.setTwoLevel(twoLevel1);
            oneLevelOne.setTwoLevel(twoLevel2);
            oneLevelOne.setTwoLevel(twoLevel3);
            oneLevelOne.setTwoLevel(twoLevel4);
            oneLevelOne.setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel oneLevelTwo("油气管理体制与法律法规",tlevel::t2,5);

            twolevel twoLevel1("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.00,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,0.00,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.00,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,1.00,false);
            oneLevelTwo.setTwoLevel(twoLevel1);
            oneLevelTwo.setTwoLevel(twoLevel2);
            oneLevelTwo.setTwoLevel(twoLevel3);
            oneLevelTwo.setTwoLevel(twoLevel4);
            oneLevelTwo.setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel oneLevelThr("对外合作开放",tlevel::t3,6);

            twolevel twoLevel1("投资开放度",tlevel::t1,0.00,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.67,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.66,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,1.00,false);
            twolevel twoLevel6("物流指数",tlevel::t6,0.87,true);
            oneLevelThr.setTwoLevel(twoLevel1);
            oneLevelThr.setTwoLevel(twoLevel2);
            oneLevelThr.setTwoLevel(twoLevel3);
            oneLevelThr.setTwoLevel(twoLevel4);
            oneLevelThr.setTwoLevel(twoLevel5);
            oneLevelThr.setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel oneLevelFour("运营制度",tlevel::t4,6);

            twolevel twoLevel1("外贸信用排名",tlevel::t1,0.00,true);
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.00,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,1.00,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.72,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.84,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,1.00,false);
            oneLevelFour.setTwoLevel(twoLevel1);
            oneLevelFour.setTwoLevel(twoLevel2);
            oneLevelFour.setTwoLevel(twoLevel3);
            oneLevelFour.setTwoLevel(twoLevel4);
            oneLevelFour.setTwoLevel(twoLevel5);
            oneLevelFour.setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel oneLevelFive("基础设施和自然环境",tlevel::t5,7);

            twolevel twoLevel1("交通运输",tlevel::t1,1.00,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,0.74,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.48,true);
            twolevel twoLevel4("教育",tlevel::t4,0.00,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.00,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.00,false);
            twolevel twoLevel7("国土面积",tlevel::t7,0.67,true);
            oneLevelFive.setTwoLevel(twoLevel1);
            oneLevelFive.setTwoLevel(twoLevel2);
            oneLevelFive.setTwoLevel(twoLevel3);
            oneLevelFive.setTwoLevel(twoLevel4);
            oneLevelFive.setTwoLevel(twoLevel5);
            oneLevelFive.setTwoLevel(twoLevel6);
            oneLevelFive.setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel oneLevelSix("经济环境",tlevel::t6,7);

            twolevel twoLevel1("石油租金",tlevel::t1,0.11,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.78,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.45,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.66,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.10,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.84,true);
            twolevel twoLevel7("劳动力市场管制",tlevel::t7,0.00,false);
            oneLevelSix.setTwoLevel(twoLevel1);
            oneLevelSix.setTwoLevel(twoLevel2);
            oneLevelSix.setTwoLevel(twoLevel3);
            oneLevelSix.setTwoLevel(twoLevel4);
            oneLevelSix.setTwoLevel(twoLevel5);
            oneLevelSix.setTwoLevel(twoLevel6);
            oneLevelSix.setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel oneLevelSeven("油气资源潜力",tlevel::t7,4);

            twolevel twoLevel1("油气储量",tlevel::t1,1.00,true);
            twolevel twoLevel2("油气产量",tlevel::t2,1.00,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,1.00,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,1.00,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

            pCountryGYH->setOneLevel(oneLevelSeven);
        }
    }

    //2.归一化数据-安哥拉
    {
        countryID = 1; //安哥拉
        country* pCountryResult = new country("安哥拉",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.26,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.43,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.48,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.96,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,1.00,true);
            oneLevelOne.setTwoLevel(twoLevel1);
            oneLevelOne.setTwoLevel(twoLevel2);
            oneLevelOne.setTwoLevel(twoLevel3);
            oneLevelOne.setTwoLevel(twoLevel4);
            oneLevelOne.setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel oneLevelTwo("油气管理体制与法律法规",tlevel::t2,5);

            twolevel twoLevel1("油气勘探开发权管理制度",tlevel::t1,1.00,true);
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.33,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,1.00,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.50,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.38,false);
            oneLevelTwo.setTwoLevel(twoLevel1);
            oneLevelTwo.setTwoLevel(twoLevel2);
            oneLevelTwo.setTwoLevel(twoLevel3);
            oneLevelTwo.setTwoLevel(twoLevel4);
            oneLevelTwo.setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel oneLevelThr("对外合作开放",tlevel::t3,6);

            twolevel twoLevel1("投资开放度",tlevel::t1,0.27,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.67,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,1.00,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,1.00,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.64,false);
            twolevel twoLevel6("物流指数",tlevel::t6,0.00,true);
            oneLevelThr.setTwoLevel(twoLevel1);
            oneLevelThr.setTwoLevel(twoLevel2);
            oneLevelThr.setTwoLevel(twoLevel3);
            oneLevelThr.setTwoLevel(twoLevel4);
            oneLevelThr.setTwoLevel(twoLevel5);
            oneLevelThr.setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel oneLevelFour("运营制度",tlevel::t4,6);

            twolevel twoLevel1("外贸信用排名",tlevel::t1,1.00,true);
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,1.00,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.32,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.00,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,1.00,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,0.00,false);
            oneLevelFour.setTwoLevel(twoLevel1);
            oneLevelFour.setTwoLevel(twoLevel2);
            oneLevelFour.setTwoLevel(twoLevel3);
            oneLevelFour.setTwoLevel(twoLevel4);
            oneLevelFour.setTwoLevel(twoLevel5);
            oneLevelFour.setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel oneLevelFive("基础设施和自然环境",tlevel::t5,7);

            twolevel twoLevel1("交通运输",tlevel::t1,0.37,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,0.34,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.05,true);
            twolevel twoLevel4("教育",tlevel::t4,0.47,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.94,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.87,false);
            twolevel twoLevel7("国土面积",tlevel::t7,1.00,true);
            oneLevelFive.setTwoLevel(twoLevel1);
            oneLevelFive.setTwoLevel(twoLevel2);
            oneLevelFive.setTwoLevel(twoLevel3);
            oneLevelFive.setTwoLevel(twoLevel4);
            oneLevelFive.setTwoLevel(twoLevel5);
            oneLevelFive.setTwoLevel(twoLevel6);
            oneLevelFive.setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel oneLevelSix("经济环境",tlevel::t6,7);

            twolevel twoLevel1("石油租金",tlevel::t1,0.55,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.56,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.00,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.41,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.04,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.21,true);
            twolevel twoLevel7("劳动力市场管制",tlevel::t7,0.00,false);
            oneLevelSix.setTwoLevel(twoLevel1);
            oneLevelSix.setTwoLevel(twoLevel2);
            oneLevelSix.setTwoLevel(twoLevel3);
            oneLevelSix.setTwoLevel(twoLevel4);
            oneLevelSix.setTwoLevel(twoLevel5);
            oneLevelSix.setTwoLevel(twoLevel6);
            oneLevelSix.setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel oneLevelSeven("油气资源潜力",tlevel::t7,4);

            twolevel twoLevel1("油气储量",tlevel::t1,0.14,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.56,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.00,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.60,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }

    //3.归一化数据- 刚果布
    {
        countryID = 2; //刚果布
        country* pCountryResult = new country("刚果布",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.38,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.22,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.36,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.36,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,1.00,true);
            oneLevelOne.setTwoLevel(twoLevel1);
            oneLevelOne.setTwoLevel(twoLevel2);
            oneLevelOne.setTwoLevel(twoLevel3);
            oneLevelOne.setTwoLevel(twoLevel4);
            oneLevelOne.setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel oneLevelTwo("油气管理体制与法律法规",tlevel::t2,5);

            twolevel twoLevel1("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.33,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,0.00,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.50,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.15,false);
            oneLevelTwo.setTwoLevel(twoLevel1);
            oneLevelTwo.setTwoLevel(twoLevel2);
            oneLevelTwo.setTwoLevel(twoLevel3);
            oneLevelTwo.setTwoLevel(twoLevel4);
            oneLevelTwo.setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel oneLevelThr("对外合作开放",tlevel::t3,6);

            twolevel twoLevel1("投资开放度",tlevel::t1,1.00,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,1.00,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,1.00,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.15,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.20,false);
            twolevel twoLevel6("物流指数",tlevel::t6,0.80,true);
            oneLevelThr.setTwoLevel(twoLevel1);
            oneLevelThr.setTwoLevel(twoLevel2);
            oneLevelThr.setTwoLevel(twoLevel3);
            oneLevelThr.setTwoLevel(twoLevel4);
            oneLevelThr.setTwoLevel(twoLevel5);
            oneLevelThr.setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel oneLevelFour("运营制度",tlevel::t4,6);

            twolevel twoLevel1("外贸信用排名",tlevel::t1,0.00,true);
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.96,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.00,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,1.00,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.09,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,0.82,false);
            oneLevelFour.setTwoLevel(twoLevel1);
            oneLevelFour.setTwoLevel(twoLevel2);
            oneLevelFour.setTwoLevel(twoLevel3);
            oneLevelFour.setTwoLevel(twoLevel4);
            oneLevelFour.setTwoLevel(twoLevel5);
            oneLevelFour.setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel oneLevelFive("基础设施和自然环境",tlevel::t5,7);

            twolevel twoLevel1("交通运输",tlevel::t1,0.05,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,0.00,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.07,true);
            twolevel twoLevel4("教育",tlevel::t4,0.39,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.99,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.98,false);
            twolevel twoLevel7("国土面积",tlevel::t7,0.08,true);
            oneLevelFive.setTwoLevel(twoLevel1);
            oneLevelFive.setTwoLevel(twoLevel2);
            oneLevelFive.setTwoLevel(twoLevel3);
            oneLevelFive.setTwoLevel(twoLevel4);
            oneLevelFive.setTwoLevel(twoLevel5);
            oneLevelFive.setTwoLevel(twoLevel6);
            oneLevelFive.setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel oneLevelSix("经济环境",tlevel::t6,7);

            twolevel twoLevel1("石油租金",tlevel::t1,1.00,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,1.00,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.98,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.00,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.06,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.55,true);
            twolevel twoLevel7("劳动力市场管制",tlevel::t7,1.00,false);
            oneLevelSix.setTwoLevel(twoLevel1);
            oneLevelSix.setTwoLevel(twoLevel2);
            oneLevelSix.setTwoLevel(twoLevel3);
            oneLevelSix.setTwoLevel(twoLevel4);
            oneLevelSix.setTwoLevel(twoLevel5);
            oneLevelSix.setTwoLevel(twoLevel6);
            oneLevelSix.setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel oneLevelSeven("油气资源潜力",tlevel::t7,4);

            twolevel twoLevel1("油气储量",tlevel::t1,0.05,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.09,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.35,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.11,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }

    //3.归一化数据-加蓬
    {
        countryID = 3; //加蓬
        country* pCountryResult = new country("加蓬",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,1.00,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,1.00,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,1.00,false);
            twolevel twoLevel4("境外风险",tlevel::t4,1.00,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,1.00,true);
            oneLevelOne.setTwoLevel(twoLevel1);
            oneLevelOne.setTwoLevel(twoLevel2);
            oneLevelOne.setTwoLevel(twoLevel3);
            oneLevelOne.setTwoLevel(twoLevel4);
            oneLevelOne.setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel oneLevelTwo("油气管理体制与法律法规",tlevel::t2,5);

            twolevel twoLevel1("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel twoLevel2("油气税费政策",tlevel::t2,1.00,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,1.00,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,1.00,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.46,false);
            oneLevelTwo.setTwoLevel(twoLevel1);
            oneLevelTwo.setTwoLevel(twoLevel2);
            oneLevelTwo.setTwoLevel(twoLevel3);
            oneLevelTwo.setTwoLevel(twoLevel4);
            oneLevelTwo.setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel oneLevelThr("对外合作开放",tlevel::t3,6);

            twolevel twoLevel1("投资开放度",tlevel::t1,0.28,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.33,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.09,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.47,false);
            twolevel twoLevel6("物流指数",tlevel::t6,0.20,true);
            oneLevelThr.setTwoLevel(twoLevel1);
            oneLevelThr.setTwoLevel(twoLevel2);
            oneLevelThr.setTwoLevel(twoLevel3);
            oneLevelThr.setTwoLevel(twoLevel4);
            oneLevelThr.setTwoLevel(twoLevel5);
            oneLevelThr.setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel oneLevelFour("运营制度",tlevel::t4,6);

            twolevel twoLevel1("外贸信用排名",tlevel::t1,0.00,true);
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.97,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.93,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.87,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.00,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,0.15,false);
            oneLevelFour.setTwoLevel(twoLevel1);
            oneLevelFour.setTwoLevel(twoLevel2);
            oneLevelFour.setTwoLevel(twoLevel3);
            oneLevelFour.setTwoLevel(twoLevel4);
            oneLevelFour.setTwoLevel(twoLevel5);
            oneLevelFour.setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel oneLevelFive("基础设施和自然环境",tlevel::t5,7);

            twolevel twoLevel1("交通运输",tlevel::t1,0.00,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,1.00,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.00,true);
            twolevel twoLevel4("教育",tlevel::t4,1.00,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.99,false);
            twolevel twoLevel6("社会治安",tlevel::t6,1.00,false);
            twolevel twoLevel7("国土面积",tlevel::t7,0.00,true);
            oneLevelFive.setTwoLevel(twoLevel1);
            oneLevelFive.setTwoLevel(twoLevel2);
            oneLevelFive.setTwoLevel(twoLevel3);
            oneLevelFive.setTwoLevel(twoLevel4);
            oneLevelFive.setTwoLevel(twoLevel5);
            oneLevelFive.setTwoLevel(twoLevel6);
            oneLevelFive.setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel oneLevelSix("经济环境",tlevel::t6,7);

            twolevel twoLevel1("石油租金",tlevel::t1,0.39,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.00,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.93,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.77,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,1.00,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.00,true);
            twolevel twoLevel7("劳动力市场管制",tlevel::t7,0.31,false);
            oneLevelSix.setTwoLevel(twoLevel1);
            oneLevelSix.setTwoLevel(twoLevel2);
            oneLevelSix.setTwoLevel(twoLevel3);
            oneLevelSix.setTwoLevel(twoLevel4);
            oneLevelSix.setTwoLevel(twoLevel5);
            oneLevelSix.setTwoLevel(twoLevel6);
            oneLevelSix.setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel oneLevelSeven("油气资源潜力",tlevel::t7,4);

            twolevel twoLevel1("油气储量",tlevel::t1,0.02,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.03,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.20,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.04,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }
}
#endif // PJAREA_H
