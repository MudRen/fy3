inherit ITEM;
void create()
{
  set_name("《道德经》", ({"daode jing" }));
        set_weight(100);
        set("unit", "本");
        set("long","道德经是道教的经典之作,当初老子西
出涵谷关,一气化三清,可以领悟道学心得.\n");
        set("value", 100);
        set("skill", ([
                "name":"daoxuexinde",         
                "exp_required": 0,                             
                "sen_cost":     10,                            
                "difficulty":   10,     
                "max_skill":    20 
        ]) );
}
