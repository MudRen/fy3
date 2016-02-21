// wang.c ������


#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
	set_name("������", ({"wang chongyang", "wang"}));
	set("gender", "����");
	set("age", 66);
	set("nickname",HIW"������"NOR);
	set("long", 
		"������ȫ��̵Ŀ�ɽ��ʦ���״��ƽ������������ˡ�������Ʈ\n"
                "Ʈ�����ۻ��䣬üĿ��񳣬����Щ�ɷ���ǵ�ζ����������һ\n"
                "ǻ��Ѫ����Ч���������������ϧ��͢���ܣ������Ļ����䣬\n"
		"�ִӵ��¾����������������Ĵ�����ִ�ȫ��̡�\n"
);
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.ju" :),
                (: perform_action, "sword.ju" :),
                (: perform_action, "sword.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: perform_action, "finger.bing" :),
		(: perform_action, "finger.bing" :),
		(: perform_action, "finger.bing" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
	}));

	set("kee", 6500);
	set("max_kee", 6500);
	set("gin", 2400);
	set("max_gin", 2400);
	set("force", 4000);
	set("max_force", 4000);
	set("force_factor", 100);
	
	set("combat_exp", 2000000);
	set("score", 500000);
	 
	set_skill("force", 200);
	set_skill("xiantian-qigong", 200);    //��������
	set_skill("sword", 200);             
	set_skill("quanzhen-jian",200);  //ȫ�潣
	set_skill("dodge",200);
	set_skill("jinyan-gong", 200);   //���㹦
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("haotian-zhang", 200);    //�����
	set_skill("literate",120);
	set_skill("daoxuexinde",140);
	set_skill("yiyang-zhi",200);  //һ��ָ   

	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("unarmed", "haotian-zhang");

	create_family("ȫ���", 1, "�ƽ�");

	set("book_count",1);
        set("inquiry", ([
		"ȫ���" :  "��ȫ��������µ����������ڡ�\n",
		"�����澭" : (: ask_jiuyin :),
		"һ��ָ" : (: ask_zhipu :),
		"�λ�ү" : (: ask_duan :),
        ]) );

	setup();
	
        carry_object("/obj/weapon/sword")->wield();
	carry_object(__DIR__"obj/greenrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30) {
        	command("say ������ʲ����������������Ǽ���ͽ��ѧϰ�ɡ�");
		return;
    	}
    	if ((int)ob->query_skill("xiantian-qigong",1) < 100 ) {
        	command("say ��ı����ڹ��ķ������,�������Ը�������书��");
		return;
    	}
	if ((int)ob->query("mingwang")<50000) {
		command("say �����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮�£���һ������Ϊͽ��\n");
		return;
	}
	command("say �ðɣ��������ʣ����ɴ����²����Ҿ����������ͽ���ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_jiuyin()
{
        mapping fam; 
	int lvl_force;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "ȫ���")
                return RANK_D->query_respect(this_player()) + 
                "�뱾�̺��޹ϸ��⻰�Ӻ�˵��";
	if (!(lvl_force = this_player()->query_skill("force",1))
	    || lvl_force < 50)
		return RANK_D->query_respect(this_player()) +
                "�Ļ����ڹ�������֮ǳ��ǿ���澭�ϵ��ϳ��书�к����档";
        return "�����澭��������ѧ���ڣ����ѽ�����ʦ���ܲ�ͨ���ܣ�\n"
		+"����....�ڹ�Ĺ�ɵ�ʯ���ڣ��һ�����һЩͼ�Ρ�\n";
}

string ask_duan()
{
	object me=this_player();
	if(me->query_temp("tmark/ָ")==4) {
		me->add_temp("tmark/ָ",1);
		return("�λ�ү�ųơ��ϵۡ����Ҵ���һ��ָ��������������ָ����\n");
	}
	else {
		me->set_temp("tmark/ָ",0);
		return("���ʶλ�ү����ô��Ī��������Ϊ�ѣ�\n");
	}
}

string ask_zhipu()
{
	object ob,me=this_player();
	if(me->query_temp("tmark/ָ")==5) {
		me->set_temp("tmark/ָ",0);
		if(query("book_count")>0) {
			ob=new(__DIR__"obj/zhifapu");
			ob->move(me);
			add("book_count",-1);
			return("�ðɣ���������࣬��־���ᣬ�Ȿָ���׾ͽ������ˡ�\n");
		}
		else 
			return("�������ˣ�ָ�����Ѿ�����ȡ���ˡ�\n");
	}
	else {
		me->set_temp("tmark/ָ",0);
		return  RANK_D->query_respect(me) +
			"��������ҽ��������ɣ�\n";
	}
}
             