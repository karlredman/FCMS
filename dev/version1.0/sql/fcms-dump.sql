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
  id int(2) NOT NULL auto_increment,
  host_id int(2) NOT NULL default '1',
  site_id int(2) NOT NULL default '1',
  page_id int(2) NOT NULL default '1',
  ref_id int(2) default NULL,
  last_updated int(4) default NULL,
  updated_by int(4) NOT NULL default '0',
  type varchar(50) default NULL,
  title varchar(100) default NULL,
  title_font_size varchar(50) default NULL,
  title_font_bg varchar(6) NOT NULL default 'FFFFFF',
  title_font_fg varchar(6) NOT NULL default '000000',
  title_font_face varchar(100) default NULL,
  title_align varchar(6) default NULL,
  security_level int(1) NOT NULL default '0',
  PRIMARY KEY(id),
  KEY(page_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'component'
--


INSERT INTO component VALUES (1,1,1,1,0,1049508345,0,'content','Sample component 1','3','FFFFFF','000000','times','center',0);

--
-- Table structure for table 'content_component'
--

CREATE TABLE content_component (
  id int(2) NOT NULL auto_increment,
  host_id int(2) NOT NULL default '1',
  site_id int(2) NOT NULL default '1',
  page_id int(2) default NULL,
  component_id int(2) default NULL,
  ref_id int(2) default NULL,
  body longblob,
  body_font_size varchar(50) default NULL,
  body_color_bg varchar(100) default '0',
  body_color_fg varchar(100) default '0',
  body_font_face varchar(100) default NULL,
  body_align varchar(6) default NULL,
  body_image varchar(100) default NULL,
  body_link varchar(100) default NULL,
  body_vlink varchar(100) default NULL,
  body_alink varchar(100) default NULL,
  security_level int(1) NOT NULL default '2',
  PRIMARY KEY  (id),
  KEY(component_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'content_component'
--


INSERT INTO content_component VALUES (1,1,1,1,1,0,'This is a test','1','0','16777215','times','center',NULL,'10092543','10079487','10092543',0);

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
  id int(2) NOT NULL auto_increment,
  host_id int(2) NOT NULL default '1',
  site_id int(2) NOT NULL default '1',
  ref_id int(2) default NULL,
  last_updated int(4) default NULL,
  updated_by int(4) NOT NULL default '0',
  page_title varchar(100) default NULL,
  file_name varchar(100) default NULL,
  parent int(2) NOT NULL default '0',
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
  KEY (site_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'page'
--


INSERT INTO page VALUES (1,1,1,0,1049508345,0,'FCMS Demo Page','FCMSDemoPage',0,'default',NULL,NULL,'FCMS Demo Page','3','FFFFFF','000000','times','center','Karl N. Redman',NULL,'speedredman@netscape.net',NULL,0,0);

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
  security_level int(1) NOT NULL default '0',
  session_id varchar(50) default NULL,
  session_date int(4) default NULL,
  PRIMARY KEY  (id),
  UNIQUE KEY id (id),
  KEY user_name (user_name)
) TYPE=MyISAM;

--
-- Dumping data for table 'users'
--


INSERT INTO users VALUES (1,1,1,'fcms_host','passwd',1049508345,NULL,NULL,NULL,NULL,NULL,NULL,0,'',0);

