#include <ansi.h>
inherit NPC;
string *level=({"扬","威","武","我"});
string *card=({"铁","铜","银","金"});
void create()
{
    set_name("古月秋",({"guyue qiu","dazhang gui"}));
    set("age",45);
    set("title","[大掌柜]");
    set("combat_exp",34444);
    set_skill("unarmed",20);
    setup();
}
void init()
{
   object ob;
    ::init();
   if (interactive(ob=this_player())&&!is_fighting())    {
           remove_call_out("greeting");
           call_out("greeting",1,ob);
         }
 }
void greeting(object ob)
{   
      object ob1;
      string str,str1,str2;
      int number;
                 number=ob->query_temp("fight/card");                          
      if (number&&number>0)
           {  
              command("say 恭喜这位"+RANK_D->query_respect(ob)+"，获得["+level[number-1]+"]级称号!\n");
              ob1=new("/d/xxy/obj/pai"+number);
               str="一枚"+card[number-1]+"牌,上面刻着\n";
               str+="["+HIR+level[number-1]+NOR+"]级武士---"+ob->short();;
           ob1->set("long",str);
           ob1->move(ob);
           ob->delete_temp("fight/card");
     message_vision("$N递给$n一块"+card[number-1]+"牌",this_object(),ob);
    }     
return;
}
