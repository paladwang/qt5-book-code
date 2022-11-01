#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <float.h>
using  std::vector;
using  std::map;
using  std::string;
using  std::pair;
using  std::make_pair;


enum tlevel {unkown=0,t1,t2,t3,t4,t5,t6,t7};

enum eCountryID {nocountry=-1,c0=0,c1,c2,c3,c4};

enum eColumn {p=5,q,r,s,t,u,v,w,x,y};

enum eDataType {ORI,GYH,RESULT};

class note {
public:
    typedef pair<int,int> noteKey;
    typedef map<noteKey,string> noteMap;
    static string getNote(int oneLevelID,int twoLevelID) {
        noteKey key(oneLevelID,twoLevelID);
        if(m_mapNote.count(key)>0) {
            return m_mapNote[key];
        } else {
            return string("noinfo");
        }
    }
private:
    static noteMap m_mapNote;

public:
    static  noteMap createNoteMap() {
        noteMap tmpNoteMap;
        tmpNoteMap[noteKey(1,1)] = "人口压力、民怨、特权阶级、公共服务，1-10分，分数越高，政局稳定性越差";
        tmpNoteMap[noteKey(1,2)] = "安全装备、国家合法性、移民和人才流失，1-10 分，分数越高，境内安全风险越高";
        tmpNoteMap[noteKey(1,3)] = "国内难民数量 ( 占总人口百分比 )，1-10 分，分数越高，难民数量越高";
        tmpNoteMap[noteKey(1,4)] = "来自国外的行为对在位政府带来的风险。国外的行为包括非暴力的外部压力例如外交压力、中止援助、贸易限制、领土纠纷、制裁等，也包括暴力的外部压力例如跨境冲突，甚至全面战争，0-10 分，分数越高，外部冲突越严重";
        tmpNoteMap[noteKey(1,5)] = "5年以上或终身制 (5)；4年(4)；3年(3)；2年(2)；1年以下(1)";

        tmpNoteMap[noteKey(2,1)] = "许可证制 ( 特许经营 ) (4)；混合制 ( 特许经营或产品分成 ) (3)；产品分成制 (2)；服务合同 (1)";
        tmpNoteMap[noteKey(2,2)] = "10项以上(1)；8～10项 (2)；6～8项 (3)；4～6项(4)；4项以下 (5)";
        tmpNoteMap[noteKey(2,3)] = "5项(5)；4项 (4)；3项 (3)；2项(2)；1项以下 (1)";
        tmpNoteMap[noteKey(2,4)] = "1项(5)；2项 (4)；3项 (3)；4项(2)；5项以下 (1)";
        tmpNoteMap[noteKey(2,5)] = "总税率在商业利润中的占比";

        tmpNoteMap[noteKey(3,1)] = "流入的外商投资占GDP的份额/%";
        tmpNoteMap[noteKey(3,2)] = "全面战略合作伙伴 (4)；战略伙伴 (3)；全面合作伙伴 (2)；合作伙伴 (1)";
        tmpNoteMap[noteKey(3,3)] = "合作紧密 (3)；合作一般 (2)；没有合作 (1)";
        tmpNoteMap[noteKey(3,4)] = "与中国进出口贸易额/亿美元";
        tmpNoteMap[noteKey(3,5)] = "初级产品加权平均关税 / %";
        tmpNoteMap[noteKey(3,6)] = "前一年指数(1 ～ 5，“差”到“好”)";

        tmpNoteMap[noteKey(4,1)] = "非洲各国外贸信用排名（2018）（A1\\A2\\A3\\A4\\B\\C\\D\\E)";
        tmpNoteMap[noteKey(4,2)] = "商品贸易（进口+出口）占GDP的百分比 %";
        tmpNoteMap[noteKey(4,3)] = "前一年成立公司所需时间/天数（天）";
        tmpNoteMap[noteKey(4,4)] = "前一年产权注册所需时间（天）";
        tmpNoteMap[noteKey(4,5)] = "准备和纳税时间（小时）";
        tmpNoteMap[noteKey(4,6)] = "执行合同所需时间/天（天）";

        tmpNoteMap[noteKey(5,1)] = "铁路、公路总长度 /km";
        tmpNoteMap[noteKey(5,2)] = "互联网普及率/%";
        tmpNoteMap[noteKey(5,3)] = "全国经常性医疗卫生支出占GDP的比重/%";
        tmpNoteMap[noteKey(5,4)] = "人口文盲率/%";
        tmpNoteMap[noteKey(5,5)] = "近三年数量/起";
        tmpNoteMap[noteKey(5,6)] = "年谋杀案件/起";
        tmpNoteMap[noteKey(5,7)] = "国土面积/104km2";

        tmpNoteMap[noteKey(6,1)] = "前一年占 GDP 百分比";
        tmpNoteMap[noteKey(6,2)] = "前一年占 GDP 百分比";
        tmpNoteMap[noteKey(6,3)] = "近5年通货膨胀率平均值";
        tmpNoteMap[noteKey(6,4)] = "近5年GDP增长率";
        tmpNoteMap[noteKey(6,5)] = "前一年人均GDP";
        tmpNoteMap[noteKey(6,6)] = "前一年石油消费量 /(1000桶·d)；天然气消费量 /(*108m3)";
        tmpNoteMap[noteKey(6,7)] = "最低工资和工作时间规定等，0-10 分，分数越高，劳动力市场管制越低";

        tmpNoteMap[noteKey(7,1)] = "2021年石油探明储量+天然气探明储量 /(*109bbl)";
        tmpNoteMap[noteKey(7,2)] = "2021年石油产量+天然气产量 /(*109bbl)";
        tmpNoteMap[noteKey(7,3)] = "2021年石油储产比；天然气储产比";
        tmpNoteMap[noteKey(7,4)] = "前一年石油出口量+天然气出口量 /(*109bbl)";

        return tmpNoteMap;
    }
};

#endif // COMMON_H
