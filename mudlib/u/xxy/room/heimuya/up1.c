// Room: carol/heimuya

inherit ROOM;


void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
int do_insert(string arg);


void create()
{
	set("short", "����");
	set("long", "      �������߳�����Ƭ�����ɭ��, ���ɳ��������˿���. ����, һ��\n"
      "���͵������������������ǰ. �����Ϸ·�������ɫ�Ľ���. ���������ƿ�������.\n"
      "��������.�������ϴ���һ������(rope). ����ȥ�����������»�ͨ��Ϣ�Ĺ���.\n "
      "�����������ƺ���Լ��һ������(basket),���µ�ǽ���ƺ���һ��ϻ��(xiazi),\n"
      "���ƺ�����һ����լ,�治֪����Ǻ�!\n" 
        );

    set("exits", ([
	"west" : __DIR__"linjxd6",
    ]));

    set("item_desc", ([
        "basket": "����һ������,��������Щ�Ź�,�ƺ�������ؿ����Խ���,ʵ�ڲ��о��������Իƽ�,����!\n",
        "rope"  : "���Ӿ�������,���������ϵĹ���,����!\n",
        "xiazi" : "����һ��ϻ��,��������һ������,ϻ�ӵĲ�����һ�����,������ԭ��!\n",
    ]));
     setup();
 
}


void init()
{
    add_action("do_insert", "insert");
    
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"basket")) )
            room = load_object(__DIR__"basket");
        if( room = find_object(__DIR__"basket") ) {
            if((int)room->query("insert_trigger")==0 ) {
                room->set("insert_trigger", 1);
                set("exits/enter", __DIR__"basket");
                room->set("exits/out", __FILE__);
                message("vision", "ֻ��һ������(basket)����������㲻��һ����\n"
                    , this_object() );
                set("item_desc", ([
        "basket" : "����һ������,�Ǵ�˵�еĽ�ͨ����.\n",
            ]));
                
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "��������õ��²���\n",this_object() );
        }

        else
            message("vision", "ERROR: basket not found\n", this_object() );
    }
    
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "ֻ�������������ϣ������������ã�\n"
             "���ƺ�������һ���˼��ɾ�����.\n"   ,
        this_object() );

    if( room = find_object(__DIR__"basket") )
    {
        room->delete("exits/out");
        
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive",20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"basket") )
    {
        room->set("exits/out", __DIR__"up2");
        message("vision", "���һ�������ƺ�һ�´����ϵ��˵��ϡ�\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"basket") ) {
        room->delete("exits/out");

        room->delete("insert_trigger");
    }
}

int do_insert(string arg)
{
    string dir;
    object ob;
    object me;

    me=this_player();

    if( !arg || arg=="" ) return 0;

    if( arg=="��" ) arg = "card1";   
    
    if( arg=="card1")
    {

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

        if( !me->query_temp("mark/cards") )
                me->set_temp("mark/cards",1);

        if( me->query_temp("mark/cards")==4)
        {

                check_trigger();
		me->delete_temp("mark/cards");
                
        }
        else    {
                me->add_temp("mark/cards",1);
                message("vision", "���һ�����㿴����������һ�ڡ�\n",me );
        }
    }
    
    return 1;
}