-- MySQL dump 8.21
--
-- Host: localhost    Database: fcms
---------------------------------------------------------
-- Server version	3.23.48-Max-log

DROP DATABASE IF EXISTS fcms;
CREATE DATABASE fcms;
USE fcms;

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


INSERT INTO content VALUES (6,1,1,1,'Welcome! Friends',5,'times','center','Thank you for using fycms.\r\n\r\n\r\nKarl N. Redman \r\nspeedredman@netscape.net',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','left');
INSERT INTO content VALUES (7,1,1,2,'This is the FCMS test page:',5,'serif','center','Try the links below to show the various pages on this demo site and to play with editing features<br><br><br><br>\r\n\r\n\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (8,1,1,3,'FCMS Demo Links:',1,'serif','left','<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=2&referp_id=1>\r\nA Link to Page 2</a>\r\n<br>\r\n<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=3&referp_id=1>\r\nA Link to Page 3</a>\r\n<br>\r\n<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=4&referp_id=1>\r\nA Link to Page 4</a>\r\n                                   ',2,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (1,1,3,1,'Sample Content Title 1',3,'times','center','This is a test 1\r\n\r\n# Sample .profile for SuSE Linux\r\n# rewritten by Christian Steinruecken <cstein@suse.de>\r\nDearest,\r\n\r\nToday I sit down to write to you for selfish reasons. I am not sure,\r\neven, if you will want to read beyond this point now that I have\r\nstated my purpose here but, I beg, continue anyway...\r\n\r\nIn the coarse of previous discussions you have stated that getting a\r\n\'Thank you\' is often the last thing you desire as a matter of\r\nformality and that the statement brings with it conotations which\r\ncause a certain feeling of loss for your position or action or self in\r\nmatters whereby you would be \'Thank you-ed\' for. And, per our\r\ndiscussions, there is evidence in you of an understanding for the fact\r\nthat in the best of times you are mutually helped in situations where\r\nyour help was offered or sought. I too subscribe to this mode of\r\nthinking but am compeled to say \'Thank you\' nonetheless. It is for\r\nthis reason that I say that this letter is of a selfish nature and\r\nimplore you, if indeed you have read thus far, to continue anyway... \r\n\r\nAs I sit here, at the computer once again, I am reminded, once again,\r\nof the many benifits our meeting has afforded me. Without going into a\r\nlong monolouge about my history I will say that I have been in many\r\nsituations in my life where I have played a role that is not unlike\r\nyours in allowing me the opportunity to stay in your apartment, eat\r\nyour food, and spend your money. But it is not for this alone that I\r\nsay \'Thank you\'. For it is apparent to me that my stay here has been,\r\nreally, the best thing in the interests of my recovery from a decade\r\nof entropy -culminated in the events of this past year or so. In my\r\nown circumstance, as I have mentioned, there have been many situations\r\nwhere I have attmpted to do for others what you have done for me -if\r\nonly I have ever been so successfull as yourself!  \r\n\r\n\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (2,1,3,2,'Sample Content Title 2',3,'times','center','This is a test 2\r\n\r\nDearest,\r\n\r\nToday I sit down to write to you for selfish reasons. I am not sure,\r\neven, if you will want to read beyond this point now that I have\r\nstated my purpose here but, I beg, continue anyway...\r\n\r\nIn the coarse of previous discussions you have stated that getting a\r\n\'Thank you\' is often the last thing you desire as a matter of\r\nformality and that the statement brings with it conotations which\r\ncause a certain feeling of loss for your position or action or self in\r\nmatters whereby you would be \'Thank you-ed\' for. And, per our\r\ndiscussions, there is evidence in you of an understanding for the fact\r\nthat in the best of times you are mutually helped in situations where\r\nyour help was offered or sought. I too subscribe to this mode of\r\nthinking but am compeled to say \'Thank you\' nonetheless. It is for\r\nthis reason that I say that this letter is of a selfish nature and\r\nimplore you, if indeed you have read thus far, to continue anyway... \r\n\r\nAs I sit here, at the computer once again, I am reminded, once again,\r\nof the many benifits our meeting has afforded me. Without going into a\r\nlong monolouge about my history I will say that I have been in many\r\nsituations in my life where I have played a role that is not unlike\r\nyours in allowing me the opportunity to stay in your apartment, eat\r\nyour food, and spend your money. But it is not for this alone that I\r\nsay \'Thank you\'. For it is apparent to me that my stay here has been,\r\nreally, the best thing in the interests of my recovery from a decade\r\nof entropy -culminated in the events of this past year or so. In my\r\nown circumstance, as I have mentioned, there have been many situations\r\nwhere I have attmpted to do for others what you have done for me -if\r\nonly I have ever been so successfull as yourself!  \r\n\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (3,1,3,3,'Sample thing',3,'times','center','This is a test stuff\r\n\r\nDearest,\r\n\r\nToday I sit down to write to you for selfish reasons. I am not sure,\r\neven, if you will want to read beyond this point now that I have\r\nstated my purpose here but, I beg, continue anyway...\r\n\r\nIn the coarse of previous discussions you have stated that getting a\r\n\'Thank you\' is often the last thing you desire as a matter of\r\nformality and that the statement brings with it conotations which\r\ncause a certain feeling of loss for your position or action or self in\r\nmatters whereby you would be \'Thank you-ed\' for. And, per our\r\ndiscussions, there is evidence in you of an understanding for the fact\r\nthat in the best of times you are mutually helped in situations where\r\nyour help was offered or sought. I too subscribe to this mode of\r\nthinking but am compeled to say \'Thank you\' nonetheless. It is for\r\nthis reason that I say that this letter is of a selfish nature and\r\nimplore you, if indeed you have read thus far, to continue anyway... \r\n\r\nAs I sit here, at the computer once again, I am reminded, once again,\r\nof the many benifits our meeting has afforded me. Without going into a\r\nlong monolouge about my history I will say that I have been in many\r\nsituations in my life where I have played a role that is not unlike\r\nyours in allowing me the opportunity to stay in your apartment, eat\r\nyour food, and spend your money. But it is not for this alone that I\r\nsay \'Thank you\'. For it is apparent to me that my stay here has been,\r\nreally, the best thing in the interests of my recovery from a decade\r\nof entropy -culminated in the events of this past year or so. In my\r\nown circumstance, as I have mentioned, there have been many situations\r\nwhere I have attmpted to do for others what you have done for me -if\r\nonly I have ever been so successfull as yourself!  \r\n\r\n',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (9,1,3,4,'FCMS Demo Links:',1,'serif','left','<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=2&referp_id=3>\r\nA Link to Page 2</a>\r\n<br>\r\n<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=4&referp_id=3>\r\nA Link to Page 4</a>',2,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (11,1,3,5,'Sample Content Title 6',5,'times','center','This is a test 6',3,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (12,1,2,3,'Sample Content Title 7',5,'times','left','This is a test 7',3,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (4,1,2,1,'Sample Content Title 4',3,'time','center','This is only a test 4 test',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (5,1,2,2,'Sample Content Title 5',1,'times','center','Sample Content 5',3,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','left');
INSERT INTO content VALUES (10,1,2,5,'FCMS Demo Links:',1,'serif','left','<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=3&referp_id=2>\r\nA Link to Page 3</a>\r\n<br>\r\n<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=4&referp_id=2>\r\nA Link to Page 4</a>',2,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (14,1,2,4,'Sample Content Title 8',5,'times','center','This is a test 8',3,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (15,1,4,1,'Sample Content Title 1',3,'times','center','This is a test 1',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (16,1,4,2,'Sample Content Title 2',3,'times','center','This is a test 2',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (17,1,4,3,'Sample Content Title 3',3,'times','center','This is a test 3',2,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (18,1,4,4,'FCMS Demo Links:',1,'serif','left','<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=2&referp_id=4>\r\nA Link to Page 2</a>\r\n<br>\r\n<a href=http://127.0.0.1/~parasyte/fcms/dev/alpha-1/?page_id=3&referp_id=4>\r\nA Link to Page 3</a>',2,'times','left',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');
INSERT INTO content VALUES (19,1,4,5,'Sample Content Title 6',5,'times','center','This is a test 6',3,'times','center',0,16777215,'images/watch.jpg','10092543','10079487','10092543','','center');

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


INSERT INTO page VALUES (1,1,0,0,'default','FCMS Home Page','FCMS: A CMS That Makes Sense',20,'times','left',1048014082,'parasyte@thing.stuff','7739350834',0);
INSERT INTO page VALUES (2,1,1,0,'doubled','Sample Page Title 2','Sample Heading: Page 2',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);
INSERT INTO page VALUES (3,1,2,0,'staggared_reverse','Sample Page Title 3','Page 3',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);
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

