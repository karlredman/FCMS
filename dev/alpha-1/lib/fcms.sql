-- MySQL dump 8.21
--
-- Host: localhost    Database: fcms
---------------------------------------------------------
-- Server version	3.23.48-Max-log

drop database if exists fcms;
create database fcms;
use fcms;

--
-- Table structure for table 'content'
--

CREATE TABLE content (
  content_id int(11) NOT NULL auto_increment,
  site_id int(11) default NULL,
  page_id int(11) default NULL,
  ref_id int(11) default NULL,
  title varchar(100) default NULL,
  title_font_size int(11) default NULL,
  title_font_face varchar(100) default NULL,
  title_align varchar(6) default NULL,
  body longblob,
  body_font_size int(11) default NULL,
  body_font_face varchar(100) default NULL,
  body_align varchar(6) default NULL,
  body_color_bg int(11) default '0',
  body_color_fg int(11) default '0',
  body_image varchar(100) default NULL,
  body_link varchar(100) default NULL,
  body_vlink varchar(100) default NULL,
  body_alink varchar(100) default NULL,
  content_image varchar(150) default NULL,
  content_image_align varchar(6) default NULL,
  PRIMARY KEY  (content_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'content'
--


INSERT INTO content VALUES (6,1,1,1,'Welcome! Friends',5,'times','center','<h3>Thank you for using FCMS.</h3>\r\n\r\n<b>Special Note:\r\n\r\n\r\nYou must aquire a License and writtn permission from Karl N. Redman in order to copy, use, distribute, or otherwise have possession of this software package.\r\n\r\n\r\nLicensing of this software package is exclusively managed by Karl N. Redman. \r\n\r\nPlease send your questions and comments to the email address below.\r\n\r\nKarl N. Redman\r\nspeedredman@netscape.net\r\n\r\n\r\n\r\nFriendly Content Management System, A.K.A.(FCMS), Copyright Karl N. Redman 2003.</b>',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','left');
INSERT INTO content VALUES (7,1,1,2,'This is the FCMS test / demo page:',5,'serif','center','Try the links below to see the various pages on this demo site and to play with editing features. <br>\r\n<br>\r\nEditing of this page is restricted.\r\n<br>\r\n\r\n\r\n\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (8,1,1,3,'FCMS Demo Links:',1,'serif','left','<a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=2&referp_id=1>\r\nA Link to Page 2</a><a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=3&referp_id=1>\r\nA Link to Page 3</a><a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=4&referp_id=1>\r\nA Link to Page 4</a>\r\n',2,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (1,1,3,1,'Sample Content 1',3,'times','center','Reaching into the freezer. My mouth waters. I know what is comming.  My hand cools with the surrounding mist of the frozen air. I reach for a handfull of ice and with the other hand, the frosted bottle.  Setting the bottle on the countertop, next to the stove, I quickly turn to grab a white towel; and proceed to encase, entomb, the ice within it. Without hesitation, I kneel to the hard lenolium floor, praying, salivating at the mouth, and attempt to particalurize the clumps of store-boughten ice. I visualize each individual cylindar turning into dust. I am beating them to death against the hard lenolium. I see blood, red, in my minds eye; this is murder, dismemberment. When the deed is done, I again stand; again feel the intensity of satisfaction -a job well done; murder. pooring the freezing vodka into the glass, the knife like edges of my ice soften; the blood of christ was never so rightious as this.\r\n\r\n\r\n-parasyte of knowledge\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (2,1,3,2,'Sample Content 2',3,'times','center','Clear is the glass\r\nas it is removed form the shelf.\r\nIt is the one reserved\r\nfor such occasions as these.\r\nTreasured, always clean,\r\nset up high,\r\nas though the highest point of the cabinet\r\nwere the pedistal for this charished thing.\r\n\r\nClear is the ice\r\nas it is removed from the freezer\r\nand placed into a black cloth.\r\nMurderous rage overtakes me\r\nas I beat the rag against the floor;\r\ndismembering, delighting\r\nin the brokenness of victoms.\r\n\r\nClear is the bottle\r\nas it is removed from the freezer too.\r\nFrosted and cold,\r\nwarm to my heart,\r\nnearly full,\r\nit containes my soul.\r\n\r\nClear is the liquid\r\npooring slow.\r\nOver the ice,\r\nsoftening there edges,\r\ninto the glass,\r\nmaking it wet,\r\ncatching light;\r\nI watch it glow.\r\n\r\nClear is my mind\r\nas I drift off\r\nto a time before now\r\nwhen things were the same\r\nbut life seemed less dull.\r\nRemembering it now\r\nI dream.\r\n\r\nClear is my reflection\r\nin the lighter that provides the flame\r\nfor this cigarett awaiting a burn.\r\nTo inhale a bit of death\r\nwith the absorbsioun of my soul\r\nsymbolizes my self.\r\n\r\nAnd I am no more.\r\n\r\n\r\n\r\n-parasyte of knowledge\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (3,1,3,3,'Sample Content 3',3,'times','center','A sip of the poison brings my body to attention; death enters my\r\nveigns. A quick light of a cigarette is in order; more death for the\r\noccasion. My ears ring louder than normal -the intensity increasing. \r\n\r\nA new crop of ice, another victom or several -more vodka, another\r\ncigarette, and death, sweat death. Maybe I\'ll write a poem.\r\n\r\n\r\n\r\n\r\n-parasyte of knowledge',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (9,1,3,4,'Sample Content 6',1,'serif','left','Industrial Blah:\r\n\r\n\r\nSystem shock, my circuits shorting -synapses firing, the lights are blinding -me in an act of osmosis decay. The cancer is growing, deconstruct, monkeys in command -reconstruct.\r\n\r\ncollapse.\r\n\r\nexpand.\r\n\r\ndisconnect, rivers flowing; time in suspension, a doppelganger friend, and self indignation -a lost nation -where does justice lie? Sugar and tweed:\r\n\r\nbleed.\r\n\r\nbleed.\r\n\r\nAnimals in cages made of glass, fairy tails of things gone by.... Kill that being inside, make it dark from the......\r\n\r\ninside.\r\n\r\noutside.\r\n\r\nButterfly wings in neverland. Idle time -grains of sand. Pin prick, soulthick, affirmation of synergetic asymmetry. life blind. Dreams in the sky -\r\n\r\nseek.\r\n\r\nhide.\r\n\r\nMetal, machine, anonymous fly -on the wall, in league with sheets; beddy-by. lift from top, sleep on high, dig shallow\r\n\r\ndie.\r\n\r\ndie.                                                             \r\n\r\nlaughter in the meadow. death be the muse. silent day. indisposed. amused. I see you. I see you.\r\n\r\nfly.\r\n\r\ntry.\r\n\r\nnothing there. in despair. love gone awry. a sinking feeling. breath takes a token drowned out by what is broken. incantation -ghosts of mine. calcification -skeletons dry.\r\n\r\nwant.\r\n\r\ndeny.\r\n\r\naccess folds into entropy, callous becomes the order of the day. What\'s the meaning of life? -you say...\r\n\r\nliving.\r\n\r\nliving.\r\n\r\nnothing else to say....  we continue without delay: now, go away.\r\n\r\n\r\n\r\n\r\n\r\n\r\n-parasyte of knowledge 2002',2,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (11,1,3,5,'FCMS: Demo Links',5,'times','center','<a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=2&referp_id=3>A Link to Page 2</a>\r\n<a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=4&referp_id=3>A Link to Page 4</a>\r\n',3,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (12,1,2,3,'The The Nymphs Reply to the Shepard',5,'times','left','If all the world and woods were young and truth in every shepard\'s tongue.  \r\nThen these passions might me move to live with thee and be thy love.  \r\n            -Sir Walter Reighly\r\n\r\n',3,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (4,1,2,1,'The Prime of Miss Jean Brodie',3,'time','center','Little Girls, I am in the business of putting old heads on young shoulders.  And all of my students are the creme de la creme. I am devoted to you in my prime and my summer in Italy has convince me that I   truly am in my Prime.  \r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (5,1,2,2,'Henry V',1,'times','center','Oh for a muse of Fire.  that would assend the brightest heaven of invention.  Then might the war like Harry assume the port of Mars and at his heels leashed in like hounds would famine sword and fire crouch for employment.',3,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','left');
INSERT INTO content VALUES (10,1,2,5,'FCMS Demo Links:',1,'serif','left','<a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=3&referp_id=2>A Link to Page 3</a>\r\n<a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=4&referp_id=2>A Link to Page 4</a>',2,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (14,1,2,4,'Little Orphan Annie',5,'times','center','\r\nLittle orphan Annie comes to our house to stay.\r\nTo wash the cups and saucers and brush the crumbs away.  \r\nTo shoo the chickens off the porch and dust the hearth and sweep.\r\nAnd make the fire and bake the bread and earn her board and keep.',3,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (15,1,4,1,'Sample Content Title 1',3,'times','center','<pre>The webcam fetishists are made up of two subclasses of the overall \r\npervisity in todays society; the voyere and the exibitionist.  Most\r\noften these fetishists travel in pairs so as to compliment one\r\nanother; as the old saying goes -opposites attract.  The exibitionists\r\nshow their stuff 24/7; a perpetual display of themselves, thier lives,\r\nand their precious things.  The voyers help their counterparts with\r\ncirculation and advertisement; taking great pleasure in thier work.\r\nEntire lives are put on display -there are archives of men and women\r\nfrom the time of their birth to their first teeth, to thier first love\r\naffairs, to their, sometimes, demise.\r\n\r\nThis sickness is widespread.  There is a premium paid by especially \r\nsick voyers for those  special places on the net that display those\r\npeople who would normally wish to remain anonymous; people who would\r\nrather live private lives. What draws so many to this kind of life?\r\nIs there nothing else to do?\r\n\r\nThe media, now, is filled with people made famouse after being \r\n\"discovered\" on the net.  Famouse singers, perfomance artists,\r\ncomedians, painters, programmers, actors, movie directors, magicians,\r\nand politicians have all come from this webcam perversity.  What has\r\nbecome of our society? It\'s no wonder that there has been a steady\r\nincrease in paranoid individuals acting out against their parinoid\r\n\"delusions\".  We\'re a society of voyers, feeding on the lives of the\r\nexibisionists and their unsuspecting victoms -yes, the exibisionists\r\nare the ones promoting, hunting down, and attacking the innocent\r\nreclusives; for the exibisionists will gain yet more popularity if\r\nthey have something to offer that is more than just themselves.  Of\r\ncoarse, the voyers are only too happy to help.\r\n\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (16,1,4,2,'Sample Content Title 2',3,'times','center','Checking out the national news, I see that the first webcam home invasion, rape, and murder is being played on a loop for all to see.  Surely this woman has died in a way that she lived -on camera for all to see; if only she had lived for her national 15 minutes of real fame.  A victom of society, I watch the clip -a snuff flick.\r\n\r\nOur heroin strips off her clothing; first her top, her braw, her necklace, and then her tight fitting spandex shorts -followed by her g-string panties.  A low income exibitionist this must be, as the footage is only in black and white and there is no sound.  I envision her panties being that certain shade of red that I know her lips to be.  Being the exibitionist that she is, she looks into the camera, smiling for all to see, and then procedes to walk out of view.\r\n\r\nThe motion scensor of the bathroom switches our view to the lavetry, where she slowly opens the clear glass door of the shower and steps in. Soon water poors over her body; her breasts heave with every breath -I\'m watching intently.  She shaves, sexily, the parts of her body that should not be obstructed to the camera\'s view.  I get excited watching her, forgetting that she is dead, forgetting that this is sick, fogetting that I\'m disgusted with all of this.  Soon the steam from the shower overtakes the camera anyway, and it switches off -no picture for the masses; just a display that says \"be right back\".\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (17,1,4,3,'Sample Content Title 3',3,'times','center','Now the camera near the front door switches on -the motion scensor\r\nknows our villan has arrived.  No alarms though; I guess she felt safe\r\nhaving her life-space broadcast 24/7.  The villan is wearing a black\r\nmask; I wonder, who could he be? Her boyfriend? A fan? If he\'s really\r\nan exibitionist, we shall soon see.\r\n\r\nHe walks past the webcam and we see another shot of him in another\r\nroom, her bedroom, opening drawers smelling underware, masterbating\r\nover a piece of laungeri layed sugestivly over a bed pillow, and\r\nfinally, putting everything back into it\'s place, walking into a\r\ncloset and closing the door.  No motion, no body heat, the webcam\r\nswitches off and we voyers \"stand-by\".    \r\n\r\nOur herion, now clean, now ready for a show walks into the bedroom; we\r\nsee this, we know what is comming.  My heart races and I try to tell\r\nher \"get out! get out\", but she doesn\'t hear me -the dead can\'t\r\nhear. Reaching into a drawer -\"oh, no! not that drawer!\" -she seems a\r\nbit nervious, as she pulls out a fimiliar looking piece of laungeri.\r\nShe\'s noticably disturbed now, feeling the moisture of the garment.\r\nNaked, confused, our herion begins to look around the room; she looks\r\ninto the camera and mouths \"What the fuck\" in such a way that I can\r\nhear her voice in my head.  What the fuck indeed? -now what?\r\n\r\nThe suspence is killing me.  I think \"please, let\'s get on with\r\nthis. Rape her already!\" -and he does.  \r\n\r\nDiscusted, I walk away from the movie clip.  Thank god there wasn\'t\r\nany sound.  Thank god there wasn\'t any color.  Her red blood would\r\nhave made me sick -sicker -and her screams would have stuck with me\r\nforever.... oh god, FUCK, I can hear her. She\'s crying \"help me, help\r\nme. isn\'t anyone watching, why won\'t you help me\" and then, nothing.\r\nWhat has become of us when real life is more terrifying than fiction\r\n-or maybe it\'s always been that way....\r\n\r\n\r\n-parasyte of knowledge 2001',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (18,1,4,4,'FCMS Demo Links:',1,'serif','left','<a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=2&referp_id=4>A Link to Page 2</a>\r\n<a href=http://127.0.0.1/~parasyte/Ankh/fcms/dev/alpha-1/?page_id=3&referp_id=4>A Link to Page 3</a>',2,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (19,1,4,5,'',5,'times','center','',3,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');

--
-- Table structure for table 'host'
--

CREATE TABLE host (
  host_id int(11) NOT NULL auto_increment,
  sites int(11) default NULL,
  program_txt blob,
  url blob,
  PRIMARY KEY  (host_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'host'
--

INSERT INTO host VALUES(1,1,'','http://127.0.0.1/~parasyte/Ankh/fcms/dev/rewrite-1');



--
-- Table structure for table 'page'
--

CREATE TABLE page (
  page_id int(11) NOT NULL auto_increment,
  site_id int(11) default NULL,
  ref_id int(11) default NULL,
  parent_id int(11) default NULL,
  type varchar(50) NOT NULL default '',
  page_title varchar(100) default NULL,
  page_heading varchar(100) default NULL,
  title_font_size int(11) default NULL,
  title_font_face varchar(100) default NULL,
  title_align varchar(6) default NULL,
  last_updated int(24) default NULL,
  email_contact varchar(100) default NULL,
  telephone_contact varchar(20) default NULL,
  code int(24) NOT NULL default '0',
  PRIMARY KEY  (page_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'page'
--


INSERT INTO page VALUES (1,1,0,0,'default','FCMS Home Page','FCMS: <br>Friendly Content Management System',20,'times','left',1048014082,'parasyte@thing.stuff','7739350834',0);
INSERT INTO page VALUES (2,1,1,0,'doubled','Sample Page Title 2','Sample Page 2',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);
INSERT INTO page VALUES (3,1,2,0,'staggared_reverse','Sample Page Title 3','Sample Page 3',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);
INSERT INTO page VALUES (4,1,3,0,'staggared','Sample Page Title 4','Sample Heading: Page 4',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);

--
-- Table structure for table 'site'
--

CREATE TABLE site (
  site_id int(11) NOT NULL auto_increment,
  host_id int(11) default NULL,
  password varchar(8) NOT NULL default '',
  name_contact varchar(100) default NULL,
  alias varchar(100) NOT NULL default '',
  homepage_id int(11) default NULL,
  PRIMARY KEY  (site_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'site'
--


INSERT INTO site VALUES (1,1,'eertwfld','karl','fcmssite',1);

