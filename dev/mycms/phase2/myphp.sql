-- MySQL dump 8.21
--
-- Host: localhost    Database: bw
---------------------------------------------------------
-- Server version	3.23.48-Max-log

--
-- Table structure for table 'homework'
--

CREATE TABLE homework (
  id int(11) NOT NULL auto_increment,
  parent_id int(11) NOT NULL default '0',
  label_1 varchar(200) NOT NULL default '',
  assignment_1 text NOT NULL,
  label_2 varchar(200) NOT NULL default '',
  assignment_2 text NOT NULL,
  label_3 varchar(200) NOT NULL default '',
  assignment_3 text NOT NULL,
  label_4 varchar(200) NOT NULL default '',
  assignment_4 text NOT NULL,
  label_5 varchar(200) NOT NULL default '',
  assignment_5 text NOT NULL,
  label_6 varchar(200) NOT NULL default '',
  assignment_6 text NOT NULL,
  label_7 varchar(200) NOT NULL default '',
  assignment_7 text NOT NULL,
  label_8 varchar(200) NOT NULL default '',
  assignment_8 text NOT NULL,
  KEY id (id)
) TYPE=MyISAM;

--
-- Dumping data for table 'homework'
--



--
-- Table structure for table 'page'
--

CREATE TABLE page (
  id int(11) NOT NULL auto_increment,
  email_contact varchar(100) default NULL,
  telephone_contact varchar(20) default NULL,
  site_id int(11) default NULL,
  content_title_1 varchar(100) default NULL,
  content_body_1 blob,
  content_size_1 int(11) default NULL,
  content_image_1 varchar(150) default NULL,
  content_title_2 varchar(100) default NULL,
  content_body_2 blob,
  content_size_2 int(11) default NULL,
  content_image_2 varchar(150) default NULL,
  content_title_3 varchar(100) default NULL,
  content_body_3 blob,
  content_size_3 int(11) default NULL,
  content_image_3 varchar(150) default NULL,
  last_updated int(24) default NULL,
  grade_level int(11) default NULL,
  subject varchar(100) default NULL,
  name_contact varchar(100) default NULL,
  page_title varchar(100) default NULL,
  content_image_1_align varchar(5) default NULL,
  content_image_2_align varchar(5) default NULL,
  content_image_3_align varchar(5) default NULL,
  font_face_1 varchar(100) default NULL,
  font_face_2 varchar(100) default NULL,
  font_face_3 varchar(100) default NULL,
  parent_id int(11) default NULL,
  code int(24) NOT NULL default '0',
  password varchar(8) NOT NULL default '',
  type varchar(50) NOT NULL default '',
  alias varchar(100) NOT NULL default '',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Dumping data for table 'page'
--


INSERT INTO page VALUES (1,'','',0,'My Hello World thing','<a href=\"http://127.0.0.1\"><img src=images/home.jpg align=left></img></a><font color=blue>hello teresa</font>\r\n\r\n<a href=\"http://127.0.0.1/~parasyte/mycms/phase2/page-display.php?id=2\"> A Link</a>\r\n\r\n<font color=blue>hello teresa</font>\r\n\r\n\r\n<center>\r\n<Italic>something in italics </Italic>\r\n</center>\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n* several newlines above this point\r\n',4,'','','',0,'','','',0,'',1048253603,0,'','','Love','','','','times','','',0,0,'eertwfld','','x.html');

