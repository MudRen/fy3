//逍遥游 1.0 BY LXH 14:59 99-1-6

#include <ansi.h>

inherit NPC;

string all_save();

void create()
{
        set_name("铁血江湖", ({ "txjh" }));
        set("gender", "无性");
        set("age", 20);
        set("per",60);
        set("mingwang",1);
        set("no_clean",1);    
        set_skill("literate", 200);

        set("title","主任助理");
        set("combat_exp", 9000000);
        setup();
}

int init()
{
                remove_call_out("init");
                call_out("init", 300);
                all_save();
}

string all_save()
{
	object *list,cpu;
	int j;

      switch(random(15))
       {
        case 0:
          command("chat "+"恭祝大家元宵快乐！。");
          break;
        case 1:
          command("chat 祝你心想事成，万事如意!");
          break;

      default : break;
       }

        list = users();
        j = sizeof(list);
                while( j-- ) {

                  if( !environment(list[j]) ) continue;

                  if( wizardp(list[j]) )
                    tell_object(list[j],"祝你节日快乐。\n");

               if(  ! list[j]->query("deng long") && 
                         ! list[j]->query("denglong_have") )
                   {/*
                    tell_object(list[j],HIM"远方隐约传来了一阵若有若无的钟声～～～～！\n\n"NOR);
                    tell_object(list[j],HIM"新年的钟声敲响了～～～～\n\n"NOR);
                    tell_object(list[j],"某人悄悄告诉你：本游戏的大钟由于长年缺乏维护，所以时间不准。。。\n");*/
                    tell_object(list[j],HIR"【铁血江湖】"NOR"祝大家元宵节愉快！\n");
                    if( random(3) ==1 )
                      {
                    list[j]->set("denglong_have",1);
tell_object(list[j],HIR"【铁血江湖】"NOR"送给你一个灯笼，祝你心想事成，万事如意。\n");
                    clone_object("/u/lxh/obj/deng")->move(list[j]);
                      }

                   }
  
                      if(  wizardp(list[j])     ) continue;
               
             }               
        command("say "+"游戏运行正常. " );

return "游戏运行正常, 处理器升级中。。。" ;

}

