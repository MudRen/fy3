// 

inherit ITEM;

void create()
{
        set_name("《圆觉经》", ({"yuanjuejing", "jing" }));
        set_weight(100);
        set("unit", "本");
        set("long",
                "大乘佛学经典，一定要读一读.\n"
             );
        set("value", 2500);
        set("skill", ([
                "name": "foxuexinde",
                "age" : 15,         
                "max_skill":    50 
        ]) );
}
 
