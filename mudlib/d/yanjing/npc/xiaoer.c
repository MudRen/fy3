inherit KZZNPC;

string query_save_file() { return DATA_DIR + "npc/高渐离";}
void create()
{
#include <kzznpc.h>
        set("area_name","燕京高升客栈");
        set("area_file","/d/yanjing/gaosheng");
        setup();
     carry_object("/d/obj/cloth/changpao")->wear();
     carry_object("/d/obj/weapon/sword/duanjian")->wield();

}
int accept_object(object who,object obj)
{
	string bh;

	bh=(string)who->query("banghui");
	if( !bh || bh!=(string)query("banghui"))	{
		if (obj->query("money_id")&&obj->value()>=200)  {
   		tell_object(who,"高渐离一摆手道:里面请。\n");
   		who->set_temp("rent_paid",1);
		"/cmds/adm/ctom.c"->save_money(this_object(),obj->value()/2);
		return 1;
		}
		else	{
		tell_object(who,"高渐离道：我说过了，住店要二两纹银。\n");
		return 0;
		}
	}
	if (obj->query("money_id")&&obj->value()>=100)  {
	tell_object(who,"高渐离一摆手道:这位兄弟，里面请！\n");
	"/cmds/adm/ctom.c"->save_money(this_object(),obj->value()/2);
	who->set_temp("rent_paid",1);
	return 1;
	}
	else	{
		tell_object(who,"高渐离道：自己弟兄也得付个一两银子意思意思吧。\n");
		return 0;
	}
}

