#include "pjarea.h"
#include "common.h"

//数据分析过程-debug版本
void pjarea::debugParse() {
    if(!this->isReady()) {
        throw std::runtime_error("the pjarea is not ready");
    }
    debugGYH(); //归一化debug数据
    debugResult(); //result数据
    debugOther(); //其他列数据
}

void pjarea::debugGYH()
{
    int countryID = 0; //0-尼日利亚,1-安哥拉,2-刚果布,3-加蓬,4-喀麦隆

    //0.归一化数据-尼日利亚
    {
        country* pCountryGYH = new country("尼日利亚",countryID);
        m_mapCountryGYH[countryID] = pCountryGYH;

        //1-政治环境
        {
            onelevel* oneLevelOne= new onelevel("政治环境",tlevel::t1);

            twolevel*  twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.00,false);
            twolevel*  twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.10,false);
            twolevel*  twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.34,false);
            twolevel*  twoLevel4 = new twolevel("境外风险",tlevel::t4,0.52,false);
            twolevel*  twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,0.00,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.00,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,1.00,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.67,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.66,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,1.00,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.87,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,1.00,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.72,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.84,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,1.00,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,1.00,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.74,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.48,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.00,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.00,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.00,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.67,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.11,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.78,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.45,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.66,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.10,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.84,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.00,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,1.00,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,1.00,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,1.00,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,1.00,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryGYH->setOneLevel(oneLevelSeven);
        }
    }

    //1.归一化数据-安哥拉
    {
        countryID = 1; //安哥拉
        country* pCountryGYH = new country("安哥拉",countryID);
        m_mapCountryGYH[countryID] = pCountryGYH;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.26,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.43,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.48,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,0.96,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,1.00,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,1.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.33,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,1.00,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.50,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.38,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.27,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.67,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,1.00,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,1.00,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.64,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.00,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,1.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,1.00,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.32,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.00,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,1.00,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.00,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.37,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.34,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.05,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.47,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.94,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.87,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,1.00,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.55,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.56,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.00,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.41,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.04,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.21,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.00,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.14,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.56,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.60,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryGYH->setOneLevel(oneLevelSeven);
        }
    }

    //2.归一化数据-刚果布
    {
        countryID = 2; //刚果布
        country* pCountryGYH = new country("刚果布",countryID);
        m_mapCountryGYH[countryID] = pCountryGYH;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.38,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.22,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.36,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,0.36,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,1.00,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.33,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.50,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.15,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,1.00,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,1.00,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,1.00,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.15,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.20,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.80,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.96,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.00,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,1.00,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.09,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.82,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.05,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.07,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.39,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.99,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.98,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.08,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,1.00,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,1.00,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.98,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.00,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.06,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.55,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,1.00,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.05,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.09,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.35,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.11,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryGYH->setOneLevel(oneLevelSeven);
        }
    }

    //3.归一化数据-加蓬
    {
        countryID = 3; //加蓬
        country* pCountryGYH = new country("加蓬",countryID);
        m_mapCountryGYH[countryID] = pCountryGYH;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,1.00,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,1.00,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,1.00,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,1.00,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,1.00,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,1.00,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,1.00,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,1.00,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.46,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.28,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.33,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.09,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.47,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.20,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.97,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.93,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.87,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.00,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.15,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,1.00,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,1.00,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.99,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,1.00,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.00,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.39,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.93,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.77,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,1.00,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.00,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.31,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.02,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.03,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.20,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.04,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryGYH->setOneLevel(oneLevelSeven);
        }
    }

    //4.归一化数据-喀麦隆
    {
        countryID = 4; //喀麦隆
        country* pCountryGYH = new country("喀麦隆",countryID);
        m_mapCountryGYH[countryID] = pCountryGYH;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.12,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.00,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.00,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,0.00,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,1.00,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,0.67,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.00,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.00,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryGYH->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.05,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.00,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.00,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,1.00,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.01,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.85,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.80,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.02,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.55,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryGYH->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.36,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.82,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,1.00,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.24,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,1.00,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.99,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.21,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.32,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,1.00,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,1.00,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.00,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,1.00,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.31,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryGYH->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.12,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.00,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryGYH->setOneLevel(oneLevelSeven);
        }
    }
}


void pjarea::debugResult()
{
    int countryID = 0; //0-尼日利亚,1-安哥拉,2-刚果布,3-加蓬,4-喀麦隆

    //0.最终结果数据-尼日利亚
    {
        country* pCountryResult = new country("尼日利亚",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel*  oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.00,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.003260706,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.009964779,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,0.015240250,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,0.00,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel*  oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.00,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.02465522,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel*  oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.019294513,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.015091224,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.020478970,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.017872556,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel*  oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.025394218,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.016419347,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.019021437,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.019850632,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel*  oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.023580999,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.017543837,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.011229047,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.00,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.00,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.00,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.013451898,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel*  oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.002665178,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.01810795,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.010545651,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.013408953,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.002127006,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.016677246,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.00,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel*  oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.023327963,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.023327963,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.021104037,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.021104037,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }

    //1.最终结果数据-安哥拉
    {
        countryID = 1; //安哥拉
        country* pCountryResult = new country("安哥拉",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel*  oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.008278805,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.013974453,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.014067923,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,0.028135846,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,0.029308173,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel*  oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.035617477,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.010838053,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,0.032514159,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.013452992,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.009259166,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel*  oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.008390048,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.019294513,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,0.028941769,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.022809671,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.013071683,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.00,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel*  oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.030773823,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.030773823,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.008104538,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.00,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.022707252,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.00,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel*  oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.008651208,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.008130359,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.001247672,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.009719037,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.019371289,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.017705758,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.020075286,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel*  oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.012920322,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.012934250,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.00,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.008287288,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.000907993,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.004245117,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.00,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel*  oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.003300352,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.013001738,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.012763039,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }

    //2.最终结果数据-刚果布
    {
        countryID = 2; //刚果布
        country* pCountryResult = new country("刚果布",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel*  oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.012174713,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.006987226,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.010550942,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,0.010550942,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,0.029308173,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel*  oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.010838053,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.013452992,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.00366060,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel*  oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.030555851,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.028941769,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,0.028941769,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.003314793,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.004170489,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.016383176,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel*  oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.029677228,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.00,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.022707252,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.001974544,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.016287698,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel*  oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.001210902,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.001621973,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.008110238,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.020251802,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.019941212,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.001517903,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel*  oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.023552066,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.02328165,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.022814646,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.00,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.001173735,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.010870855,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.019478806,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel*  oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.001229274,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.00207986,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.007449508,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.002353929,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }

    //3.最终结果数据-加蓬
    {
        countryID = 3; //加蓬
        country* pCountryResult = new country("加蓬",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel*  oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.032141241,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.032141241,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.029308173,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,0.029308173,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,0.029308173,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel*  oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.032514159,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,0.032514159,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.026905985,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.01141246,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel*  oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.008570911,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.009647256,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.002128599,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.00967927,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.004095794,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel*  oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.029766141,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.023713277,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.01970188,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.00,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.003009683,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel*  oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.023580999,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.020545306,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.020251802,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.020298105,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.00,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel*  oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.009270186,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.021586224,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.015588384,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.020301405,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.00,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.006062505,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel*  oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.000358628,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.000766505,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.004142163,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.000932804,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }

    //4.最终结果数据-喀麦隆
    {
        countryID = 4; //喀麦隆
        country* pCountryResult = new country("喀麦隆",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel*  oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,0.003895908,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,0.00,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,0.00,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,0.00,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,0.029308173,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel*  oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,0.021676106,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,0.00,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.00,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountryResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel*  oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.001376571,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,0.00,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,0.00,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,0.02047897,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel*  oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,0.000375411,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,0.0216121,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,0.018199195,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,0.000526545,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,0.010976492,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountryResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel*  oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,0.008552349,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,0.019223126,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,0.023580999,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,0.004892641,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,0.020545306,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,0.020084658,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,0.004254229,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel*  oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.007362573,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.02328165,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.020301405,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,0.00,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.019903019,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.006062505,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountryResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel*  oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,0.00,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.00,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,0.002623373,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.00,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }
}

void pjarea::debugOriData()
{
    int countryID = 0; //0-尼日利亚,1-安哥拉,2-刚果布,3-加蓬,4-喀麦隆

    //0.原始评价数据-尼日利亚
    {
        country* pCountry = new country("尼日利亚",countryID);
        m_mapCountry[countryID] = pCountry;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,9.3,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,7.9,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,6.6,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,5.7,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,4.0,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,2.00,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,1.00,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,1.00,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,1.00,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.348,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,0.7,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,3,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,2,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,192.7,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,11.8,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,2.53,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,6,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,21.06,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,7.2,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,91.66,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,343,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,399,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,198200,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,35.8,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,3.7,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,29.27,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,76,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,17843,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,92.38,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.074,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.0098,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.557,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.0296,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,2097.09,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,275,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,10,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,72.12,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,1.03,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,69.74,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.86,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountry->setOneLevel(oneLevelSeven);
        }
    }

    //1.原始评价数据-安哥拉
    {
        countryID = 1; //安哥拉
        country* pCountry = new country("安哥拉",countryID);
        m_mapCountry[countryID] = pCountry;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,8.4,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,7.1,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,5.9,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,4.6,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,5,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,3,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,2,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,4,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,3,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.491,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,9.05,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,3,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,3,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,277.55,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,14.18,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,2.05,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,7,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,52.21,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,36,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,190,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,287,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,1296,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,79800,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,19.88,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,2.9,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,19,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,10,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,2414,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,124.67,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.251,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.0072,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.9725,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,-0.0644,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,1776.17,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,82.3,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,10,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,11.12,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.60,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,18.68,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.53,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountry->setOneLevel(oneLevelSeven);
        }
    }

    //2.原始评价数据-刚果布
    {
        countryID = 2; //刚果布
        country* pCountry = new country("刚果布",countryID);
        m_mapCountry[countryID] = pCountry;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,8.0,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,7.6,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,6.5,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,6.1,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,5,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,2,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,2,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,1,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,3,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.543,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,31.11,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,4,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,3,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,63.24,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,17.04,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,2.49,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,6,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,51.1,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,49.5,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,54,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,602,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,560,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,20795,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,6.13,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,2.93,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,20.7,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,7,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,466,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,34.2,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.4345,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.0124,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.0736,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,-0.2165,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,1846.13,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,185,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,1.1,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,4.81,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.13,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,36.71,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.12,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountry->setOneLevel(oneLevelSeven);
        }
    }

    //3.原始评价数据-加蓬
    {
        countryID = 3; //加蓬
        country* pCountry = new country("加蓬",countryID);
        m_mapCountry[countryID] = pCountry;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,6.0,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,5.8,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,3.3,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,4.5,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,5,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,2,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,4,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,4,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,5,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.471,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,9.23,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,2,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,2,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,50.2,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,15.27,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,2.16,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,6,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,51.19,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,10,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,72,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,632,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,1160,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,11192,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,46.01,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,2.8,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,7.56,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,7,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,155,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,26.8,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.122,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.0696,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,6881.72,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.901,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,16.5,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,0.188,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,0.0007,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,2.16,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.08,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,28.71,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.06,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountry->setOneLevel(oneLevelSeven);
        }
    }

    //4.原始评价数据-喀麦隆
    {
        countryID = 4; //喀麦隆
        country* pCountry = new country("喀麦隆",countryID);
        m_mapCountry[countryID] = pCountry;

        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            twolevel* twoLevel1 = new twolevel("政局稳定性",tlevel::t1,8.9,false);
            twolevel* twoLevel2 = new twolevel("境内安全风险",tlevel::t2,8.1,false);
            twolevel* twoLevel3 = new twolevel("政治动荡性",tlevel::t3,8.3,false);
            twolevel* twoLevel4 = new twolevel("境外风险",tlevel::t4,7.0,false);
            twolevel* twoLevel5 = new twolevel("政治大选间隔",tlevel::t5,5,true);
            oneLevelOne->setTwoLevel(twoLevel1);
            oneLevelOne->setTwoLevel(twoLevel2);
            oneLevelOne->setTwoLevel(twoLevel3);
            oneLevelOne->setTwoLevel(twoLevel4);
            oneLevelOne->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            twolevel* twoLevel1 = new twolevel("油气勘探开发权管理制度",tlevel::t1,2,true);
            twolevel* twoLevel2 = new twolevel("油气税费政策",tlevel::t2,1,true);
            twolevel* twoLevel3 = new twolevel("油气投资促进政策",tlevel::t3,3,true);
            twolevel* twoLevel4 = new twolevel("环境保护法律法规",tlevel::t4,1,true);
            twolevel* twoLevel5 = new twolevel("一般税负情况",tlevel::t5,0.577,false);
            oneLevelTwo->setTwoLevel(twoLevel1);
            oneLevelTwo->setTwoLevel(twoLevel2);
            oneLevelTwo->setTwoLevel(twoLevel3);
            oneLevelTwo->setTwoLevel(twoLevel4);
            oneLevelTwo->setTwoLevel(twoLevel5);

            pCountry->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            twolevel* twoLevel1 = new twolevel("投资开放度",tlevel::t1,2.07,true);
            twolevel* twoLevel2 = new twolevel("与中国外交关系",tlevel::t2,1,true);
            twolevel* twoLevel3 = new twolevel("与中国油气合作现状",tlevel::t3,2,true);
            twolevel* twoLevel4 = new twolevel("与中国经贸关系",tlevel::t4,26.8,true);
            twolevel* twoLevel5 = new twolevel("初级产品关税",tlevel::t5,18.38,false);
            twolevel* twoLevel6 = new twolevel("物流指数",tlevel::t6,2.6,true);
            oneLevelThr->setTwoLevel(twoLevel1);
            oneLevelThr->setTwoLevel(twoLevel2);
            oneLevelThr->setTwoLevel(twoLevel3);
            oneLevelThr->setTwoLevel(twoLevel4);
            oneLevelThr->setTwoLevel(twoLevel5);
            oneLevelThr->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            twolevel* twoLevel1 = new twolevel("外贸信用排名",tlevel::t1,6,true);
            twolevel* twoLevel2 = new twolevel("跨境贸易便利性",tlevel::t2,21.44,true);
            twolevel* twoLevel3 = new twolevel("成立公司便利性",tlevel::t3,13.5,false);
            twolevel* twoLevel4 = new twolevel("产权注册便利性",tlevel::t4,81,false);
            twolevel* twoLevel5 = new twolevel("纳税所需时间",tlevel::t5,624,false);
            twolevel* twoLevel6 = new twolevel("合同强制执行时间",tlevel::t6,800,false);
            oneLevelFour->setTwoLevel(twoLevel1);
            oneLevelFour->setTwoLevel(twoLevel2);
            oneLevelFour->setTwoLevel(twoLevel3);
            oneLevelFour->setTwoLevel(twoLevel4);
            oneLevelFour->setTwoLevel(twoLevel5);
            oneLevelFour->setTwoLevel(twoLevel6);

            pCountry->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            twolevel* twoLevel1 = new twolevel("交通运输",tlevel::t1,79016,true);
            twolevel* twoLevel2 = new twolevel("信息化水平",tlevel::t2,38.64,true);
            twolevel* twoLevel3 = new twolevel("医疗条件",tlevel::t3,4.69,true);
            twolevel* twoLevel4 = new twolevel("教育",tlevel::t4,24.1,false);
            twolevel* twoLevel5 = new twolevel("海盗",tlevel::t5,6,false);
            twolevel* twoLevel6 = new twolevel("社会治安",tlevel::t6,341,false);
            twolevel* twoLevel7 = new twolevel("国土面积",tlevel::t7,47.54,true);
            oneLevelFive->setTwoLevel(twoLevel1);
            oneLevelFive->setTwoLevel(twoLevel2);
            oneLevelFive->setTwoLevel(twoLevel3);
            oneLevelFive->setTwoLevel(twoLevel4);
            oneLevelFive->setTwoLevel(twoLevel5);
            oneLevelFive->setTwoLevel(twoLevel6);
            oneLevelFive->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            twolevel* twoLevel1 = new twolevel("石油租金",tlevel::t1,0.028,true);
            twolevel* twoLevel2 = new twolevel("天然气租金",tlevel::t2,0.0044,true);
            twolevel* twoLevel3 = new twolevel("经济稳定情况",tlevel::t3,0.0552,false);
            twolevel* twoLevel4 = new twolevel("经济增速",tlevel::t4,0.1561,true);
            twolevel* twoLevel5 = new twolevel("经济发展水平",tlevel::t5,1537.13,true);
            twolevel* twoLevel6 = new twolevel("油气消费情况",tlevel::t6,325,true);
            twolevel* twoLevel7 = new twolevel("劳动力市场管制",tlevel::t7,7.23,false);
            oneLevelSix->setTwoLevel(twoLevel1);
            oneLevelSix->setTwoLevel(twoLevel2);
            oneLevelSix->setTwoLevel(twoLevel3);
            oneLevelSix->setTwoLevel(twoLevel4);
            oneLevelSix->setTwoLevel(twoLevel5);
            oneLevelSix->setTwoLevel(twoLevel6);
            oneLevelSix->setTwoLevel(twoLevel7);

            pCountry->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            twolevel* twoLevel1 = new twolevel("油气储量",tlevel::t1,1.07,true);
            twolevel* twoLevel2 = new twolevel("油气产量",tlevel::t2,0.04,true);
            twolevel* twoLevel3 = new twolevel("油气储采比",tlevel::t3,25.03,true);
            twolevel* twoLevel4 = new twolevel("油气出口量",tlevel::t4,0.03,true);
            oneLevelSeven->setTwoLevel(twoLevel1);
            oneLevelSeven->setTwoLevel(twoLevel2);
            oneLevelSeven->setTwoLevel(twoLevel3);
            oneLevelSeven->setTwoLevel(twoLevel4);

            pCountry->setOneLevel(oneLevelSeven);
        }
    }
}

//设置其他值
void pjarea::debugOther() {
    /*
     *标准差结果
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
     */

    int columnID = eColumn::p;
    //1) 标准差结果: m_bzcOneResult
    m_bzcOneResult = new column("标准差",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,0.3483);
            myCell* curCell2 = new myCell(tlevel::t2,0.3554);
            myCell* curCell3 = new myCell(tlevel::t3,0.3241);
            myCell* curCell4 = new myCell(tlevel::t4,0.3764);
            myCell* curCell5 = new myCell(tlevel::t5,0.4000);
            oneLevelOne->setTwoLevel(curCell1);
            oneLevelOne->setTwoLevel(curCell2);
            oneLevelOne->setTwoLevel(curCell3);
            oneLevelOne->setTwoLevel(curCell4);
            oneLevelOne->setTwoLevel(curCell5);

            m_bzcOneResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,0.4000);
            myCell* curCell2 = new myCell(tlevel::t2,0.3651);
            myCell* curCell3 = new myCell(tlevel::t3,0.4522);
            myCell* curCell4 = new myCell(tlevel::t4,0.3742);
            myCell* curCell5 = new myCell(tlevel::t5,0.3429);
            oneLevelTwo->setTwoLevel(curCell1);
            oneLevelTwo->setTwoLevel(curCell2);
            oneLevelTwo->setTwoLevel(curCell3);
            oneLevelTwo->setTwoLevel(curCell4);
            oneLevelTwo->setTwoLevel(curCell5);

            m_bzcOneResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,0.3589);
            myCell* curCell2 = new myCell(tlevel::t2,0.3399);
            myCell* curCell3 = new myCell(tlevel::t3,0.4899);
            myCell* curCell4 = new myCell(tlevel::t4,0.3861);
            myCell* curCell5 = new myCell(tlevel::t5,0.3466);
            myCell* curCell6 = new myCell(tlevel::t6,0.3978);
            oneLevelThr->setTwoLevel(curCell1);
            oneLevelThr->setTwoLevel(curCell2);
            oneLevelThr->setTwoLevel(curCell3);
            oneLevelThr->setTwoLevel(curCell4);
            oneLevelThr->setTwoLevel(curCell5);
            oneLevelThr->setTwoLevel(curCell6);

            m_bzcOneResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,0.4000);
            myCell* curCell2 = new myCell(tlevel::t2,0.4759);
            myCell* curCell3 = new myCell(tlevel::t3,0.3927);
            myCell* curCell4 = new myCell(tlevel::t4,0.3512);
            myCell* curCell5 = new myCell(tlevel::t5,0.4361);
            myCell* curCell6 = new myCell(tlevel::t6,0.3813);
            oneLevelFour->setTwoLevel(curCell1);
            oneLevelFour->setTwoLevel(curCell2);
            oneLevelFour->setTwoLevel(curCell3);
            oneLevelFour->setTwoLevel(curCell4);
            oneLevelFour->setTwoLevel(curCell5);
            oneLevelFour->setTwoLevel(curCell6);

            m_bzcOneResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,0.3562);
            myCell* curCell2 = new myCell(tlevel::t2,0.3606);
            myCell* curCell3 = new myCell(tlevel::t3,0.3804);
            myCell* curCell4 = new myCell(tlevel::t4,0.3315);
            myCell* curCell5 = new myCell(tlevel::t5,0.3919);
            myCell* curCell6 = new myCell(tlevel::t6,0.3872);
            myCell* curCell7 = new myCell(tlevel::t7,0.3829);
            oneLevelFive->setTwoLevel(curCell1);
            oneLevelFive->setTwoLevel(curCell2);
            oneLevelFive->setTwoLevel(curCell3);
            oneLevelFive->setTwoLevel(curCell4);
            oneLevelFive->setTwoLevel(curCell5);
            oneLevelFive->setTwoLevel(curCell6);
            oneLevelFive->setTwoLevel(curCell7);

            m_bzcOneResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,0.3532);
            myCell* curCell2 = new myCell(tlevel::t2,0.3492);
            myCell* curCell3 = new myCell(tlevel::t3,0.3917);
            myCell* curCell4 = new myCell(tlevel::t4,0.3415);
            myCell* curCell5 = new myCell(tlevel::t5,0.3807);
            myCell* curCell6 = new myCell(tlevel::t6,0.3733);
            myCell* curCell7 = new myCell(tlevel::t7,0.3653);
            oneLevelSix->setTwoLevel(curCell1);
            oneLevelSix->setTwoLevel(curCell2);
            oneLevelSix->setTwoLevel(curCell3);
            oneLevelSix->setTwoLevel(curCell4);
            oneLevelSix->setTwoLevel(curCell5);
            oneLevelSix->setTwoLevel(curCell6);
            oneLevelSix->setTwoLevel(curCell7);

            m_bzcOneResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,0.3822);
            myCell* curCell2 = new myCell(tlevel::t2,0.3887);
            myCell* curCell3 = new myCell(tlevel::t3,0.3517);
            myCell* curCell4 = new myCell(tlevel::t4,0.3899);
            oneLevelSeven->setTwoLevel(curCell1);
            oneLevelSeven->setTwoLevel(curCell2);
            oneLevelSeven->setTwoLevel(curCell3);
            oneLevelSeven->setTwoLevel(curCell4);

            m_bzcOneResult->setOneLevel(oneLevelSeven);
        }
    }

    columnID = eColumn::q;
    //2) 重要性之比前驱值: m_preOneZYX
    m_preOneZYX = new column("重要性之比前驱值",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,0.0);
            myCell* curCell2 = new myCell(tlevel::t2,0.9801);
            myCell* curCell3 = new myCell(tlevel::t3,1.0967);
            myCell* curCell4 = new myCell(tlevel::t4,0.8609);
            myCell* curCell5 = new myCell(tlevel::t5,0.9411);
            oneLevelOne->setTwoLevel(curCell1);
            oneLevelOne->setTwoLevel(curCell2);
            oneLevelOne->setTwoLevel(curCell3);
            oneLevelOne->setTwoLevel(curCell4);
            oneLevelOne->setTwoLevel(curCell5);

            m_preOneZYX->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1.0954);
            myCell* curCell3 = new myCell(tlevel::t3,0.8076);
            myCell* curCell4 = new myCell(tlevel::t4,1.2084);
            myCell* curCell5 = new myCell(tlevel::t5,1.0913);
            oneLevelTwo->setTwoLevel(curCell1);
            oneLevelTwo->setTwoLevel(curCell2);
            oneLevelTwo->setTwoLevel(curCell3);
            oneLevelTwo->setTwoLevel(curCell4);
            oneLevelTwo->setTwoLevel(curCell5);

            m_preOneZYX->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1.0558);
            myCell* curCell3 = new myCell(tlevel::t3,0.6939);
            myCell* curCell4 = new myCell(tlevel::t4,1.2688);
            myCell* curCell5 = new myCell(tlevel::t5,1.1138);
            myCell* curCell6 = new myCell(tlevel::t6,0.8715);
            oneLevelThr->setTwoLevel(curCell1);
            oneLevelThr->setTwoLevel(curCell2);
            oneLevelThr->setTwoLevel(curCell3);
            oneLevelThr->setTwoLevel(curCell4);
            oneLevelThr->setTwoLevel(curCell5);
            oneLevelThr->setTwoLevel(curCell6);

            m_preOneZYX->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,0.8405);
            myCell* curCell3 = new myCell(tlevel::t3,1.2118);
            myCell* curCell4 = new myCell(tlevel::t4,1.1183);
            myCell* curCell5 = new myCell(tlevel::t5,0.8052);
            myCell* curCell6 = new myCell(tlevel::t6,1.1439);
            oneLevelFour->setTwoLevel(curCell1);
            oneLevelFour->setTwoLevel(curCell2);
            oneLevelFour->setTwoLevel(curCell3);
            oneLevelFour->setTwoLevel(curCell4);
            oneLevelFour->setTwoLevel(curCell5);
            oneLevelFour->setTwoLevel(curCell6);

            m_preOneZYX->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,0.9877);
            myCell* curCell3 = new myCell(tlevel::t3,0.9480);
            myCell* curCell4 = new myCell(tlevel::t4,1.1478);
            myCell* curCell5 = new myCell(tlevel::t5,0.8458);
            myCell* curCell6 = new myCell(tlevel::t6,1.0122);
            myCell* curCell7 = new myCell(tlevel::t7,1.0111);
            oneLevelFive->setTwoLevel(curCell1);
            oneLevelFive->setTwoLevel(curCell2);
            oneLevelFive->setTwoLevel(curCell3);
            oneLevelFive->setTwoLevel(curCell4);
            oneLevelFive->setTwoLevel(curCell5);
            oneLevelFive->setTwoLevel(curCell6);
            oneLevelFive->setTwoLevel(curCell7);

            m_preOneZYX->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1.0116);
            myCell* curCell3 = new myCell(tlevel::t3,0.8914);
            myCell* curCell4 = new myCell(tlevel::t4,1.1468);
            myCell* curCell5 = new myCell(tlevel::t5,0.8971);
            myCell* curCell6 = new myCell(tlevel::t6,1.0200);
            myCell* curCell7 = new myCell(tlevel::t7,1.0218);
            oneLevelSix->setTwoLevel(curCell1);
            oneLevelSix->setTwoLevel(curCell2);
            oneLevelSix->setTwoLevel(curCell3);
            oneLevelSix->setTwoLevel(curCell4);
            oneLevelSix->setTwoLevel(curCell5);
            oneLevelSix->setTwoLevel(curCell6);
            oneLevelSix->setTwoLevel(curCell7);

            m_preOneZYX->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,0.9832);
            myCell* curCell3 = new myCell(tlevel::t3,1.1054);
            myCell* curCell4 = new myCell(tlevel::t4,0.9019);
            oneLevelSeven->setTwoLevel(curCell1);
            oneLevelSeven->setTwoLevel(curCell2);
            oneLevelSeven->setTwoLevel(curCell3);
            oneLevelSeven->setTwoLevel(curCell4);

            m_preOneZYX->setOneLevel(oneLevelSeven);
        }
    }

    columnID = eColumn::r;
    //3) 重要性之比: m_oneZYX
    m_oneZYX = new column("重要性之比",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,0.0);
            myCell* curCell2 = new myCell(tlevel::t2,1);
            myCell* curCell3 = new myCell(tlevel::t3,1.0967);
            myCell* curCell4 = new myCell(tlevel::t4,1);
            myCell* curCell5 = new myCell(tlevel::t5,1);
            oneLevelOne->setTwoLevel(curCell1);
            oneLevelOne->setTwoLevel(curCell2);
            oneLevelOne->setTwoLevel(curCell3);
            oneLevelOne->setTwoLevel(curCell4);
            oneLevelOne->setTwoLevel(curCell5);

            m_oneZYX->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1.0954);
            myCell* curCell3 = new myCell(tlevel::t3,1);
            myCell* curCell4 = new myCell(tlevel::t4,1.2084);
            myCell* curCell5 = new myCell(tlevel::t5,1.0913);
            oneLevelTwo->setTwoLevel(curCell1);
            oneLevelTwo->setTwoLevel(curCell2);
            oneLevelTwo->setTwoLevel(curCell3);
            oneLevelTwo->setTwoLevel(curCell4);
            oneLevelTwo->setTwoLevel(curCell5);

            m_oneZYX->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1.0558);
            myCell* curCell3 = new myCell(tlevel::t3,1);
            myCell* curCell4 = new myCell(tlevel::t4,1.2688);
            myCell* curCell5 = new myCell(tlevel::t5,1.1138);
            myCell* curCell6 = new myCell(tlevel::t6,1);
            oneLevelThr->setTwoLevel(curCell1);
            oneLevelThr->setTwoLevel(curCell2);
            oneLevelThr->setTwoLevel(curCell3);
            oneLevelThr->setTwoLevel(curCell4);
            oneLevelThr->setTwoLevel(curCell5);
            oneLevelThr->setTwoLevel(curCell6);

            m_oneZYX->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1);
            myCell* curCell3 = new myCell(tlevel::t3,1.2118);
            myCell* curCell4 = new myCell(tlevel::t4,1.1183);
            myCell* curCell5 = new myCell(tlevel::t5,1);
            myCell* curCell6 = new myCell(tlevel::t6,1.1439);
            oneLevelFour->setTwoLevel(curCell1);
            oneLevelFour->setTwoLevel(curCell2);
            oneLevelFour->setTwoLevel(curCell3);
            oneLevelFour->setTwoLevel(curCell4);
            oneLevelFour->setTwoLevel(curCell5);
            oneLevelFour->setTwoLevel(curCell6);

            m_oneZYX->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1);
            myCell* curCell3 = new myCell(tlevel::t3,1);
            myCell* curCell4 = new myCell(tlevel::t4,1.1478);
            myCell* curCell5 = new myCell(tlevel::t5,1);
            myCell* curCell6 = new myCell(tlevel::t6,1.0122);
            myCell* curCell7 = new myCell(tlevel::t7,1.0111);
            oneLevelFive->setTwoLevel(curCell1);
            oneLevelFive->setTwoLevel(curCell2);
            oneLevelFive->setTwoLevel(curCell3);
            oneLevelFive->setTwoLevel(curCell4);
            oneLevelFive->setTwoLevel(curCell5);
            oneLevelFive->setTwoLevel(curCell6);
            oneLevelFive->setTwoLevel(curCell7);

            m_oneZYX->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1.0116);
            myCell* curCell3 = new myCell(tlevel::t3,1);
            myCell* curCell4 = new myCell(tlevel::t4,1.1468);
            myCell* curCell5 = new myCell(tlevel::t5,1);
            myCell* curCell6 = new myCell(tlevel::t6,1.0200);
            myCell* curCell7 = new myCell(tlevel::t7,1.0218);
            oneLevelSix->setTwoLevel(curCell1);
            oneLevelSix->setTwoLevel(curCell2);
            oneLevelSix->setTwoLevel(curCell3);
            oneLevelSix->setTwoLevel(curCell4);
            oneLevelSix->setTwoLevel(curCell5);
            oneLevelSix->setTwoLevel(curCell6);
            oneLevelSix->setTwoLevel(curCell7);

            m_oneZYX->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            myCell* curCell2 = new myCell(tlevel::t2,1);
            myCell* curCell3 = new myCell(tlevel::t3,1.1054);
            myCell* curCell4 = new myCell(tlevel::t4,1);
            oneLevelSeven->setTwoLevel(curCell1);
            oneLevelSeven->setTwoLevel(curCell2);
            oneLevelSeven->setTwoLevel(curCell3);
            oneLevelSeven->setTwoLevel(curCell4);

            m_oneZYX->setOneLevel(oneLevelSeven);
        }
    }

    columnID = eColumn::s;
    //4) 指标权重: m_onePower
    m_onePower = new column("指标权重",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,0.211167956);
            myCell* curCell2 = new myCell(tlevel::t2,0.211167956);
            myCell* curCell3 = new myCell(tlevel::t3,0.192554696);
            myCell* curCell4 = new myCell(tlevel::t4,0.192554696);
            myCell* curCell5 = new myCell(tlevel::t5,0.192554696);
            oneLevelOne->setTwoLevel(curCell1);
            oneLevelOne->setTwoLevel(curCell2);
            oneLevelOne->setTwoLevel(curCell3);
            oneLevelOne->setTwoLevel(curCell4);
            oneLevelOne->setTwoLevel(curCell5);

            m_onePower->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,0.234006825);
            myCell* curCell2 = new myCell(tlevel::t2,0.213618028);
            myCell* curCell3 = new myCell(tlevel::t3,0.213618028);
            myCell* curCell4 = new myCell(tlevel::t4,0.17677232);
            myCell* curCell5 = new myCell(tlevel::t5,0.161984798);
            oneLevelTwo->setTwoLevel(curCell1);
            oneLevelTwo->setTwoLevel(curCell2);
            oneLevelTwo->setTwoLevel(curCell3);
            oneLevelTwo->setTwoLevel(curCell4);
            oneLevelTwo->setTwoLevel(curCell5);

            m_onePower->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,0.20075194);
            myCell* curCell2 = new myCell(tlevel::t2,0.190147423);
            myCell* curCell3 = new myCell(tlevel::t3,0.190147423);
            myCell* curCell4 = new myCell(tlevel::t4,0.149859543);
            myCell* curCell5 = new myCell(tlevel::t5,0.134546836);
            myCell* curCell6 = new myCell(tlevel::t6,0.134546836);
            oneLevelThr->setTwoLevel(curCell1);
            oneLevelThr->setTwoLevel(curCell2);
            oneLevelThr->setTwoLevel(curCell3);
            oneLevelThr->setTwoLevel(curCell4);
            oneLevelThr->setTwoLevel(curCell5);
            oneLevelThr->setTwoLevel(curCell6);

            m_onePower->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,0.202184019);
            myCell* curCell2 = new myCell(tlevel::t2,0.202184019);
            myCell* curCell3 = new myCell(tlevel::t3,0.166840013);
            myCell* curCell4 = new myCell(tlevel::t4,0.149186646);
            myCell* curCell5 = new myCell(tlevel::t5,0.149186646);
            myCell* curCell6 = new myCell(tlevel::t6,0.130418656);
            oneLevelFour->setTwoLevel(curCell1);
            oneLevelFour->setTwoLevel(curCell2);
            oneLevelFour->setTwoLevel(curCell3);
            oneLevelFour->setTwoLevel(curCell4);
            oneLevelFour->setTwoLevel(curCell5);
            oneLevelFour->setTwoLevel(curCell6);

            m_onePower->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,0.154927164);
            myCell* curCell2 = new myCell(tlevel::t2,0.154927164);
            myCell* curCell3 = new myCell(tlevel::t3,0.154927164);
            myCell* curCell4 = new myCell(tlevel::t4,0.134982664);
            myCell* curCell5 = new myCell(tlevel::t5,0.134982664);
            myCell* curCell6 = new myCell(tlevel::t6,0.133358549);
            myCell* curCell7 = new myCell(tlevel::t7,0.131894632);
            oneLevelFive->setTwoLevel(curCell1);
            oneLevelFive->setTwoLevel(curCell2);
            oneLevelFive->setTwoLevel(curCell3);
            oneLevelFive->setTwoLevel(curCell4);
            oneLevelFive->setTwoLevel(curCell5);
            oneLevelFive->setTwoLevel(curCell6);
            oneLevelFive->setTwoLevel(curCell7);

            m_onePower->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,0.156909167);
            myCell* curCell2 = new myCell(tlevel::t2,0.155107593);
            myCell* curCell3 = new myCell(tlevel::t3,0.155107593);
            myCell* curCell4 = new myCell(tlevel::t4,0.135252531);
            myCell* curCell5 = new myCell(tlevel::t5,0.135252531);
            myCell* curCell6 = new myCell(tlevel::t6,0.132598393);
            myCell* curCell7 = new myCell(tlevel::t7,0.129772191);
            oneLevelSix->setTwoLevel(curCell1);
            oneLevelSix->setTwoLevel(curCell2);
            oneLevelSix->setTwoLevel(curCell3);
            oneLevelSix->setTwoLevel(curCell4);
            oneLevelSix->setTwoLevel(curCell5);
            oneLevelSix->setTwoLevel(curCell6);
            oneLevelSix->setTwoLevel(curCell7);

            m_onePower->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,0.262513087);
            myCell* curCell2 = new myCell(tlevel::t2,0.262513087);
            myCell* curCell3 = new myCell(tlevel::t3,0.237486913);
            myCell* curCell4 = new myCell(tlevel::t4,0.237486913);
            oneLevelSeven->setTwoLevel(curCell1);
            oneLevelSeven->setTwoLevel(curCell2);
            oneLevelSeven->setTwoLevel(curCell3);
            oneLevelSeven->setTwoLevel(curCell4);

            m_onePower->setOneLevel(oneLevelSeven);
        }
    }

    columnID = eColumn::t;
    //5) 准则层标准差: m_bzcTwoResult
    m_bzcTwoResult = new column("准则层标准差",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,1.8042);
            oneLevelOne->setTwoLevel(curCell1);

            m_bzcTwoResult->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,1.9343);
            oneLevelTwo->setTwoLevel(curCell1);

            m_bzcTwoResult->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,2.3193);
            oneLevelThr->setTwoLevel(curCell1);

            m_bzcTwoResult->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,2.4372);
            oneLevelFour->setTwoLevel(curCell1);

            m_bzcTwoResult->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,2.5908);
            oneLevelFive->setTwoLevel(curCell1);

            m_bzcTwoResult->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,2.5549);
            oneLevelSix->setTwoLevel(curCell1);

            m_bzcTwoResult->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,1.5126);
            oneLevelSeven->setTwoLevel(curCell1);

            m_bzcTwoResult->setOneLevel(oneLevelSeven);
        }
    }

    columnID = eColumn::u;
    //6) 准则层重要性之比前驱: m_preTwoZYX
    m_preTwoZYX = new column("准则层重要性之比前驱",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            oneLevelOne->setTwoLevel(curCell1);

            m_preTwoZYX->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,0.9327);
            oneLevelTwo->setTwoLevel(curCell1);

            m_preTwoZYX->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,0.8340);
            oneLevelThr->setTwoLevel(curCell1);

            m_preTwoZYX->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,0.9516);
            oneLevelFour->setTwoLevel(curCell1);

            m_preTwoZYX->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,0.9407);
            oneLevelFive->setTwoLevel(curCell1);

            m_preTwoZYX->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,1.0140);
            oneLevelSix->setTwoLevel(curCell1);

            m_preTwoZYX->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,1.6891);
            oneLevelSeven->setTwoLevel(curCell1);

            m_preTwoZYX->setOneLevel(oneLevelSeven);
        }
    }

    columnID = eColumn::v;
    //7) 准则层重要性之比: m_twoZYX
    m_twoZYX = new column("准则层重要性之比",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,0.0000);
            oneLevelOne->setTwoLevel(curCell1);

            m_twoZYX->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,1.0000);
            oneLevelTwo->setTwoLevel(curCell1);

            m_twoZYX->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,1.0000);
            oneLevelThr->setTwoLevel(curCell1);

            m_twoZYX->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,1);
            oneLevelFour->setTwoLevel(curCell1);

            m_twoZYX->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,1);
            oneLevelFive->setTwoLevel(curCell1);

            m_twoZYX->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,1.0140);
            oneLevelSix->setTwoLevel(curCell1);

            m_twoZYX->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,1.6891);
            oneLevelSeven->setTwoLevel(curCell1);

            m_twoZYX->setOneLevel(oneLevelSeven);
        }
    }

    columnID = eColumn::w;
    //8) 准则层权重: m_twoPower
    m_twoPower = new column("准则层权重",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,0.152207111);
            oneLevelOne->setTwoLevel(curCell1);

            m_twoPower->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,0.152207111);
            oneLevelTwo->setTwoLevel(curCell1);

            m_twoPower->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,0.152207111);
            oneLevelThr->setTwoLevel(curCell1);

            m_twoPower->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,0.152207111);
            oneLevelFour->setTwoLevel(curCell1);

            m_twoPower->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,0.152207111);
            oneLevelFive->setTwoLevel(curCell1);

            m_twoPower->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,0.150100482);
            oneLevelSix->setTwoLevel(curCell1);

            m_twoPower->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,0.088863961);
            oneLevelSeven->setTwoLevel(curCell1);

            m_twoPower->setOneLevel(oneLevelSeven);
        }
    }

    columnID = eColumn::x;
    //9) 指标的全局权重: m_allPower
    m_allPower = new column("指标的全局权重",columnID);
    {
        //1-政治环境
        {
            onelevel* oneLevelOne = new onelevel("政治环境",tlevel::t1);

            myCell* curCell1 = new myCell(tlevel::t1,0.032141241);
            myCell* curCell2 = new myCell(tlevel::t2,0.032141241);
            myCell* curCell3 = new myCell(tlevel::t3,0.029308173);
            myCell* curCell4 = new myCell(tlevel::t4,0.029308173);
            myCell* curCell5 = new myCell(tlevel::t5,0.029308173);
            oneLevelOne->setTwoLevel(curCell1);
            oneLevelOne->setTwoLevel(curCell2);
            oneLevelOne->setTwoLevel(curCell3);
            oneLevelOne->setTwoLevel(curCell4);
            oneLevelOne->setTwoLevel(curCell5);

            m_allPower->setOneLevel(oneLevelOne);
        }
        //2-油气管理体制与法律法规
        {
            onelevel* oneLevelTwo = new onelevel("油气管理体制与法律法规",tlevel::t2);

            myCell* curCell1 = new myCell(tlevel::t1,0.035617477);
            myCell* curCell2 = new myCell(tlevel::t2,0.032514159);
            myCell* curCell3 = new myCell(tlevel::t3,0.032514159);
            myCell* curCell4 = new myCell(tlevel::t4,0.026905985);
            myCell* curCell5 = new myCell(tlevel::t5,0.02465522);
            oneLevelTwo->setTwoLevel(curCell1);
            oneLevelTwo->setTwoLevel(curCell2);
            oneLevelTwo->setTwoLevel(curCell3);
            oneLevelTwo->setTwoLevel(curCell4);
            oneLevelTwo->setTwoLevel(curCell5);

            m_allPower->setOneLevel(oneLevelTwo);
        }
        //3-对外合作开放
        {
            onelevel* oneLevelThr = new onelevel("对外合作开放",tlevel::t3);

            myCell* curCell1 = new myCell(tlevel::t1,0.030555851);
            myCell* curCell2 = new myCell(tlevel::t2,0.028941769);
            myCell* curCell3 = new myCell(tlevel::t3,0.028941769);
            myCell* curCell4 = new myCell(tlevel::t4,0.022809671);
            myCell* curCell5 = new myCell(tlevel::t5,0.02047897);
            myCell* curCell6 = new myCell(tlevel::t6,0.02047897);
            oneLevelThr->setTwoLevel(curCell1);
            oneLevelThr->setTwoLevel(curCell2);
            oneLevelThr->setTwoLevel(curCell3);
            oneLevelThr->setTwoLevel(curCell4);
            oneLevelThr->setTwoLevel(curCell5);
            oneLevelThr->setTwoLevel(curCell6);

            m_allPower->setOneLevel(oneLevelThr);
        }
        //4-运营制度
        {
            onelevel* oneLevelFour = new onelevel("运营制度",tlevel::t4);

            myCell* curCell1 = new myCell(tlevel::t1,0.030773823);
            myCell* curCell2 = new myCell(tlevel::t2,0.030773823);
            myCell* curCell3 = new myCell(tlevel::t3,0.025394218);
            myCell* curCell4 = new myCell(tlevel::t4,0.022707252);
            myCell* curCell5 = new myCell(tlevel::t5,0.022707252);
            myCell* curCell6 = new myCell(tlevel::t6,0.019850632);
            oneLevelFour->setTwoLevel(curCell1);
            oneLevelFour->setTwoLevel(curCell2);
            oneLevelFour->setTwoLevel(curCell3);
            oneLevelFour->setTwoLevel(curCell4);
            oneLevelFour->setTwoLevel(curCell5);
            oneLevelFour->setTwoLevel(curCell6);

            m_allPower->setOneLevel(oneLevelFour);
        }
        //5-基础设施和自然环境
        {
            onelevel* oneLevelFive = new onelevel("基础设施和自然环境",tlevel::t5);

            myCell* curCell1 = new myCell(tlevel::t1,0.023580999);
            myCell* curCell2 = new myCell(tlevel::t2,0.023580999);
            myCell* curCell3 = new myCell(tlevel::t3,0.023580999);
            myCell* curCell4 = new myCell(tlevel::t4,0.020545306);
            myCell* curCell5 = new myCell(tlevel::t5,0.020545306);
            myCell* curCell6 = new myCell(tlevel::t6,0.020298105);
            myCell* curCell7 = new myCell(tlevel::t7,0.020075286);
            oneLevelFive->setTwoLevel(curCell1);
            oneLevelFive->setTwoLevel(curCell2);
            oneLevelFive->setTwoLevel(curCell3);
            oneLevelFive->setTwoLevel(curCell4);
            oneLevelFive->setTwoLevel(curCell5);
            oneLevelFive->setTwoLevel(curCell6);
            oneLevelFive->setTwoLevel(curCell7);

            m_allPower->setOneLevel(oneLevelFive);
        }
        //6-经济环境
        {
            onelevel* oneLevelSix = new onelevel("经济环境",tlevel::t6);

            myCell* curCell1 = new myCell(tlevel::t1,0.023552066);
            myCell* curCell2 = new myCell(tlevel::t2,0.02328165);
            myCell* curCell3 = new myCell(tlevel::t3,0.02328165);
            myCell* curCell4 = new myCell(tlevel::t4,0.020301405);
            myCell* curCell5 = new myCell(tlevel::t5,0.020301405);
            myCell* curCell6 = new myCell(tlevel::t6,0.019903019);
            myCell* curCell7 = new myCell(tlevel::t7,0.019478806);
            oneLevelSix->setTwoLevel(curCell1);
            oneLevelSix->setTwoLevel(curCell2);
            oneLevelSix->setTwoLevel(curCell3);
            oneLevelSix->setTwoLevel(curCell4);
            oneLevelSix->setTwoLevel(curCell5);
            oneLevelSix->setTwoLevel(curCell6);
            oneLevelSix->setTwoLevel(curCell7);

            m_allPower->setOneLevel(oneLevelSix);
        }
        //7-油气资源潜力
        {
            onelevel* oneLevelSeven = new onelevel("油气资源潜力",tlevel::t7);

            myCell* curCell1 = new myCell(tlevel::t1,0.023327963);
            myCell* curCell2 = new myCell(tlevel::t2,0.023327963);
            myCell* curCell3 = new myCell(tlevel::t3,0.021104037);
            myCell* curCell4 = new myCell(tlevel::t4,0.021104037);
            oneLevelSeven->setTwoLevel(curCell1);
            oneLevelSeven->setTwoLevel(curCell2);
            oneLevelSeven->setTwoLevel(curCell3);
            oneLevelSeven->setTwoLevel(curCell4);

            m_allPower->setOneLevel(oneLevelSeven);
        }
    }

}
