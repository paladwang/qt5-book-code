#include "pjarea.h"


void pjarea::debugGYH()
{
    int countryID = 0; //0-尼日利亚,1-安哥拉,2-刚果布,3-加蓬,4-喀麦隆

    //0.归一化数据-尼日利亚
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

    //1.归一化数据-安哥拉
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

    //2.归一化数据-刚果布
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

    //4.归一化数据-喀麦隆
    {
        countryID = 4; //喀麦隆
        country* pCountryResult = new country("喀麦隆",countryID);
        m_mapCountryResult[countryID] = pCountryResult;

        //1-政治环境
        {
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.12,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.00,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.00,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.00,false);
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
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.00,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,0.67,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.00,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.00,false);
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

            twolevel twoLevel1("投资开放度",tlevel::t1,0.05,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.00,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.00,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.00,false);
            twolevel twoLevel6("物流指数",tlevel::t6,1.00,true);
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
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.01,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.85,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.80,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.02,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,0.55,false);
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

            twolevel twoLevel1("交通运输",tlevel::t1,0.36,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,0.82,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,1.00,true);
            twolevel twoLevel4("教育",tlevel::t4,0.24,false);
            twolevel twoLevel5("海盗",tlevel::t5,1.00,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.99,false);
            twolevel twoLevel7("国土面积",tlevel::t7,0.21,true);
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

            twolevel twoLevel1("石油租金",tlevel::t1,0.00,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.32,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,1.00,false);
            twolevel twoLevel4("经济增速",tlevel::t4,1.00,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.00,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,1.00,true);
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

            twolevel twoLevel1("油气储量",tlevel::t1,0.00,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.00,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.12,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.00,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
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
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.00,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.003260706,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.009964779,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.015240250,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,0.00,true);
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
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.00,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,0.00,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.00,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.02465522,false);
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

            twolevel twoLevel1("投资开放度",tlevel::t1,0.00,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.019294513,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.015091224,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.020478970,false);
            twolevel twoLevel6("物流指数",tlevel::t6,0.017872556,true);
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
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.00,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.025394218,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.016419347,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.019021437,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,0.019850632,false);
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

            twolevel twoLevel1("交通运输",tlevel::t1,0.023580999,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,0.017543837,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.011229047,true);
            twolevel twoLevel4("教育",tlevel::t4,0.00,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.00,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.00,false);
            twolevel twoLevel7("国土面积",tlevel::t7,0.013451898,true);
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

            twolevel twoLevel1("石油租金",tlevel::t1,0.002665178,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.01810795,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.010545651,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.013408953,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.002127006,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.016677246,true);
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

            twolevel twoLevel1("油气储量",tlevel::t1,0.023327963,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.023327963,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.021104037,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.021104037,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

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
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.008278805,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.013974453,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.014067923,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.028135846,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,0.029308173,true);
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

            twolevel twoLevel1("油气勘探开发权管理制度",tlevel::t1,0.035617477,true);
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.010838053,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,0.032514159,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.013452992,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.009259166,false);
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

            twolevel twoLevel1("投资开放度",tlevel::t1,0.008390048,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.019294513,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,0.028941769,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.022809671,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.013071683,false);
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

            twolevel twoLevel1("外贸信用排名",tlevel::t1,0.030773823,true);
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.030773823,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.008104538,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.00,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.022707252,false);
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

            twolevel twoLevel1("交通运输",tlevel::t1,0.008651208,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,0.008130359,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.001247672,true);
            twolevel twoLevel4("教育",tlevel::t4,0.009719037,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.019371289,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.017705758,false);
            twolevel twoLevel7("国土面积",tlevel::t7,0.020075286,true);
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

            twolevel twoLevel1("石油租金",tlevel::t1,0.012920322,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.012934250,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.00,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.008287288,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.000907993,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.004245117,true);
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

            twolevel twoLevel1("油气储量",tlevel::t1,0.003300352,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.013001738,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.00,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.012763039,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

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
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.012174713,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.006987226,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.010550942,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.010550942,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,0.029308173,true);
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
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.010838053,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,0.00,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.013452992,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.00366060,false);
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

            twolevel twoLevel1("投资开放度",tlevel::t1,0.030555851,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.028941769,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,0.028941769,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.003314793,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.004170489,false);
            twolevel twoLevel6("物流指数",tlevel::t6,0.016383176,true);
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
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.029677228,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.00,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.022707252,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.001974544,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,0.016287698,false);
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

            twolevel twoLevel1("交通运输",tlevel::t1,0.001210902,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,0.00,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.001621973,true);
            twolevel twoLevel4("教育",tlevel::t4,0.008110238,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.020251802,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.019941212,false);
            twolevel twoLevel7("国土面积",tlevel::t7,0.001517903,true);
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

            twolevel twoLevel1("石油租金",tlevel::t1,0.023552066,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.02328165,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.022814646,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.00,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.001173735,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.010870855,true);
            twolevel twoLevel7("劳动力市场管制",tlevel::t7,0.019478806,false);
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

            twolevel twoLevel1("油气储量",tlevel::t1,0.001229274,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.00207986,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.007449508,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.002353929,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

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
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.032141241,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.032141241,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.029308173,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.029308173,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,0.029308173,true);
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
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.032514159,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,0.032514159,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.026905985,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.01141246,false);
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

            twolevel twoLevel1("投资开放度",tlevel::t1,0.008570911,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.009647256,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.002128599,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.00967927,false);
            twolevel twoLevel6("物流指数",tlevel::t6,0.004095794,true);
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
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.029766141,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.023713277,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.01970188,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.00,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,0.003009683,false);
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
            twolevel twoLevel2("信息化水平",tlevel::t2,0.023580999,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.00,true);
            twolevel twoLevel4("教育",tlevel::t4,0.020545306,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.020251802,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.020298105,false);
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

            twolevel twoLevel1("石油租金",tlevel::t1,0.009270186,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.00,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.021586224,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.015588384,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.020301405,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.00,true);
            twolevel twoLevel7("劳动力市场管制",tlevel::t7,0.006062505,false);
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

            twolevel twoLevel1("油气储量",tlevel::t1,0.000358628,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.000766505,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.004142163,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.000932804,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

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
            onelevel oneLevelOne("政治环境",tlevel::t1,5);

            twolevel twoLevel1("政局稳定性",tlevel::t1,0.003895908,false);
            twolevel twoLevel2("境内安全风险",tlevel::t2,0.00,false);
            twolevel twoLevel3("政治动荡性",tlevel::t3,0.00,false);
            twolevel twoLevel4("境外风险",tlevel::t4,0.00,false);
            twolevel twoLevel5("政治大选间隔",tlevel::t5,0.029308173,true);
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
            twolevel twoLevel2("油气税费政策",tlevel::t2,0.00,true);
            twolevel twoLevel3("油气投资促进政策",tlevel::t3,0.021676106,true);
            twolevel twoLevel4("环境保护法律法规",tlevel::t4,0.00,true);
            twolevel twoLevel5("一般税负情况",tlevel::t5,0.00,false);
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

            twolevel twoLevel1("投资开放度",tlevel::t1,0.001376571,true);
            twolevel twoLevel2("与中国外交关系",tlevel::t2,0.00,true);
            twolevel twoLevel3("与中国油气合作现状",tlevel::t3,0.00,true);
            twolevel twoLevel4("与中国经贸关系",tlevel::t4,0.00,true);
            twolevel twoLevel5("初级产品关税",tlevel::t5,0.00,false);
            twolevel twoLevel6("物流指数",tlevel::t6,0.02047897,true);
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
            twolevel twoLevel2("跨境贸易便利性",tlevel::t2,0.000375411,true);
            twolevel twoLevel3("成立公司便利性",tlevel::t3,0.0216121,false);
            twolevel twoLevel4("产权注册便利性",tlevel::t4,0.018199195,false);
            twolevel twoLevel5("纳税所需时间",tlevel::t5,0.000526545,false);
            twolevel twoLevel6("合同强制执行时间",tlevel::t6,0.010976492,false);
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

            twolevel twoLevel1("交通运输",tlevel::t1,0.008552349,true);
            twolevel twoLevel2("信息化水平",tlevel::t2,0.019223126,true);
            twolevel twoLevel3("医疗条件",tlevel::t3,0.023580999,true);
            twolevel twoLevel4("教育",tlevel::t4,0.004892641,false);
            twolevel twoLevel5("海盗",tlevel::t5,0.020545306,false);
            twolevel twoLevel6("社会治安",tlevel::t6,0.020084658,false);
            twolevel twoLevel7("国土面积",tlevel::t7,0.004254229,true);
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

            twolevel twoLevel1("石油租金",tlevel::t1,0.00,true);
            twolevel twoLevel2("天然气租金",tlevel::t2,0.007362573,true);
            twolevel twoLevel3("经济稳定情况",tlevel::t3,0.02328165,false);
            twolevel twoLevel4("经济增速",tlevel::t4,0.020301405,true);
            twolevel twoLevel5("经济发展水平",tlevel::t5,0.00,true);
            twolevel twoLevel6("油气消费情况",tlevel::t6,0.019903019,true);
            twolevel twoLevel7("劳动力市场管制",tlevel::t7,0.006062505,false);
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

            twolevel twoLevel1("油气储量",tlevel::t1,0.00,true);
            twolevel twoLevel2("油气产量",tlevel::t2,0.00,true);
            twolevel twoLevel3("油气储采比",tlevel::t3,0.002623373,true);
            twolevel twoLevel4("油气出口量",tlevel::t4,0.00,true);
            oneLevelSeven.setTwoLevel(twoLevel1);
            oneLevelSeven.setTwoLevel(twoLevel2);
            oneLevelSeven.setTwoLevel(twoLevel3);
            oneLevelSeven.setTwoLevel(twoLevel4);

            pCountryResult->setOneLevel(oneLevelSeven);
        }
    }
}
