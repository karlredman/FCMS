-- MySQL dump 8.21
--
-- Host: localhost    Database: fcms
---------------------------------------------------------
-- Server version	3.23.48-Max-log
DROP DATABASE IF EXISTS fcms;
CREATE DATABASE fcms;
USE fcms;


--
-- Table structure for table 'component'
--

CREATE TABLE component (
  id int(8) NOT NULL auto_increment,
  host_id int(2) NOT NULL default '1',
  site_id int(2) NOT NULL default '1',
  page_id int(6) default NULL,
  ref_id int(8) default NULL,
  last_updated int(23) default NULL,
  updated_by int(4) NOT NULL default '0',
  type varchar(50) default NULL,
  title varchar(100) default NULL,
  title_font_size varchar(50) NOT NULL default '1',
  title_font_bg varchar(6) NOT NULL default 'FFFFFF',
  title_font_fg varchar(6) NOT NULL default '000000',
  title_font_face varchar(100) NOT NULL default 'times',
  title_align varchar(6) NOT NULL default 'center',
  security_level int(1) NOT NULL default '2',
  PRIMARY KEY  (id),
  KEY page_id (page_id),
  KEY ref_id (ref_id),
  KEY ref_id_2 (ref_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'component'
--


INSERT INTO component VALUES (1,1,1,1,0,NULL,0,'content','Sample Component Title','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (7,1,1,1,4,2003,0,'content','Image in a content_component (right justified)','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (10,1,1,1,7,2003,0,'content','','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (5,1,1,1,3,2003,0,'content','New Component Title','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (9,1,1,1,6,2003,0,'content','Login Component template','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (11,1,1,1,8,2003,0,'content','New Component Title','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (12,1,1,1,9,2003,0,'content','','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (13,1,1,1,10,2003,0,'content','New Component Title','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (14,1,1,1,11,2003,0,'content','New Component Title','1','FFFFFF','000000','times','center',2);
INSERT INTO component VALUES (15,1,1,1,12,2003,0,'content','New Component Title','1','FFFFFF','000000','times','center',2);

--
-- Table structure for table 'content_component'
--

CREATE TABLE content_component (
  id int(8) NOT NULL auto_increment,
  host_id int(2) NOT NULL default '1',
  site_id int(2) NOT NULL default '1',
  page_id int(6) default NULL,
  component_id int(8) default NULL,
  ref_id int(8) default NULL,
  body longblob,
  body_font_size varchar(50) NOT NULL default '1',
  body_color_bg varchar(100) default '0',
  body_color_fg varchar(100) default '0',
  body_font_face varchar(100) NOT NULL default 'times',
  body_align varchar(6) NOT NULL default 'center',
  body_image varchar(100) default NULL,
  body_link varchar(100) default NULL,
  body_vlink varchar(100) default NULL,
  body_alink varchar(100) default NULL,
  security_level int(1) NOT NULL default '2',
  PRIMARY KEY  (id),
  KEY component_id (component_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'content_component'
--


INSERT INTO content_component VALUES (1,1,1,1,1,0,'\r\n\r\n\r\nThis is a test for fun and profit\r\n\r\n\r\n\r\n','1','0','16777215','times','center',NULL,'10092543','10079487','10092543',0);
INSERT INTO content_component VALUES (5,1,1,1,5,3,'Sample Content text.\r\n','1','0','0','times','center',NULL,NULL,NULL,NULL,2);
INSERT INTO content_component VALUES (11,1,1,1,11,8,'Sample Content text.','1','0','0','times','center',NULL,NULL,NULL,NULL,2);
INSERT INTO content_component VALUES (10,1,1,1,10,7,'','1','0','0','times','center',NULL,NULL,NULL,NULL,2);
INSERT INTO content_component VALUES (7,1,1,1,7,4,'<img src=http://127.0.0.1/~parasyte/fcms/images/logo.gif align=right>','1','0','0','times','center',NULL,NULL,NULL,NULL,2);
INSERT INTO content_component VALUES (12,1,1,1,12,9,'','1','0','0','times','center',NULL,NULL,NULL,NULL,2);
INSERT INTO content_component VALUES (13,1,1,1,13,10,'Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.\r\n\r\n\r\nSample Content text.Sample Content text.Sample Content text.\r\nSample Content text.Sample Content text.\r\n\r\nSample Content text.Sample Content text.','1','0','0','times','center',NULL,NULL,NULL,NULL,2);
INSERT INTO content_component VALUES (14,1,1,1,14,11,'Sample Content text. Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.\r\n\r\n\r\nSample Content text.Sample Content text.Sample Content text.\r\nSample Content text.Sample Content text.\r\n\r\nSample Content text.Sample Content text.\r\n','1','0','0','times','center',NULL,NULL,NULL,NULL,2);
INSERT INTO content_component VALUES (9,1,1,1,9,6,'<form action=index.php METHOD=POST> <input type=text name=f_user value=fcms_host size=40>\r\n<input type=password name=f_pass value=passwd size=40>\r\n<input type=submit value=Login><input type=reset> <input type=hidden name=host_id value=1><input type=hidden name=site_id value=1><input type=hidden name=page_id value=1><input type=hidden name=referp_id value=><input type=hidden name=component_id value=><input type=hidden name=mode value=authorize><input type=hidden name=action value=login></form>\r\n','1','0','0','times','center',NULL,NULL,NULL,NULL,2);
INSERT INTO content_component VALUES (15,1,1,1,15,12,'Sample Content text. Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.Sample Content text.\r\n\r\n\r\nSample Content text.Sample Content text.Sample Content text.\r\nSample Content text.Sample Content text.\r\n\r\nSample Content text.Sample Content text.\r\n','1','0','0','times','center',NULL,NULL,NULL,NULL,2);

--
-- Table structure for table 'host'
--

CREATE TABLE host (
  id int(11) NOT NULL auto_increment,
  admin_info blob,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Dumping data for table 'host'
--


INSERT INTO host VALUES (1,'');

--
-- Table structure for table 'page'
--

CREATE TABLE page (
  id int(6) NOT NULL auto_increment,
  host_id int(2) NOT NULL default '1',
  site_id int(2) NOT NULL default '1',
  ref_id int(6) default NULL,
  last_updated int(24) default NULL,
  updated_by int(4) NOT NULL default '0',
  page_title varchar(100) default NULL,
  file_name varchar(100) default NULL,
  parent int(6) NOT NULL default '0',
  theme varchar(50) NOT NULL default '',
  header blob,
  footer blob,
  heading varchar(100) default NULL,
  heading_font_size varchar(6) NOT NULL default '0',
  heading_font_fg varchar(6) NOT NULL default 'FFFFFF',
  heading_font_bg varchar(6) NOT NULL default '000000',
  heading_font_face varchar(50) NOT NULL default 'times',
  heading_font_align varchar(6) NOT NULL default 'left',
  contact_name varchar(50) default NULL,
  contact_phone varchar(25) default NULL,
  contact_email varchar(50) default NULL,
  contact_other blob,
  ssl_enable int(1) NOT NULL default '0',
  security_level int(1) NOT NULL default '1',
  PRIMARY KEY  (id),
  KEY site_id (site_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'page'
--


INSERT INTO page VALUES (1,1,1,0,1049508345,0,'FCMS Demo Page','FCMSDemoPage',0,'staggared',NULL,NULL,'<b>FCMS Demo Page</b>','3','FFFFFF','000000','times','center','Karl N. Redman',NULL,'speedredman@netscape.net',NULL,0,0);
INSERT INTO page VALUES (2,1,1,1,NULL,0,NULL,NULL,0,'',NULL,NULL,NULL,'0','FFFFFF','000000','times','left',NULL,NULL,NULL,NULL,0,1);
INSERT INTO page VALUES (3,1,1,2,NULL,0,NULL,NULL,1,'',NULL,NULL,NULL,'0','FFFFFF','000000','times','left',NULL,NULL,NULL,NULL,0,1);

--
-- Table structure for table 'site'
--

CREATE TABLE site (
  id int(2) NOT NULL auto_increment,
  host_id int(2) NOT NULL default '0',
  title varchar(100) default NULL,
  alias varchar(100) NOT NULL default '',
  url varchar(100) default NULL,
  homepage_id int(2) NOT NULL default '0',
  last_updated int(4) NOT NULL default '0',
  updated_by int(4) NOT NULL default '0',
  header blob,
  footer blob,
  contact_name varchar(50) default NULL,
  contact_phone varchar(25) default NULL,
  contact_email varchar(50) default NULL,
  contact_other blob,
  security_level int(1) NOT NULL default '0',
  PRIMARY KEY  (id),
  KEY alias (alias)
) TYPE=MyISAM;

--
-- Dumping data for table 'site'
--


INSERT INTO site VALUES (1,1,'FCMS Demo Site','fmcs-demo','127.0.0.1/fcms/',1,1049508345,0,NULL,NULL,'Karl N. Redman',NULL,'speedredman@netscape.net',NULL,0);

--
-- Table structure for table 'users'
--

CREATE TABLE users (
  id int(4) NOT NULL auto_increment,
  host_id int(2) default NULL,
  site_id int(2) default NULL,
  user_name varchar(100) default NULL,
  password varchar(100) default NULL,
  last_login int(4) default NULL,
  contact_name varchar(50) default NULL,
  contact_address1 varchar(100) default NULL,
  contact_address2 varchar(100) default NULL,
  contact_phone varchar(25) default NULL,
  contact_email varchar(50) default NULL,
  contact_other blob,
  security_level int(1) NOT NULL default '2',
  session_id varchar(50) default NULL,
  session_date int(4) default NULL,
  PRIMARY KEY  (id),
  UNIQUE KEY id (id),
  KEY user_name (user_name)
) TYPE=MyISAM;

--
-- Dumping data for table 'users'
--


INSERT INTO users VALUES (1,1,1,'fcms_host','passwd',1049508345,NULL,NULL,NULL,NULL,NULL,NULL,0,'b4b003fe4282a4d7254424d7fef1c0cf',23);

