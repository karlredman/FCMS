-- MySQL dump 8.21
--
-- Host: localhost    Database: mycms
---------------------------------------------------------
-- Server version	3.23.48-Max-log
DROP DATABASE IF EXISTS mycms;
CREATE DATABASE mycms;
USE mycms;


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
  body blob,
  body_font_size int(11) default NULL,
  body_font_face varchar(100) default NULL,
  body_align varchar(6) default NULL,
  body_color_bg int(11) default 0,
  body_color_fg int(11) default 0,
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

--page 1
INSERT INTO content VALUES (6,1,1,1,'Welcome!',5,'times','center','Thank you for using mycms. Please contact Karl N. Redman at speedredman@netscape.net if you have any problems',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','left');
INSERT INTO content VALUES (7,1,1,2,'This is the mycms test page:',5,'serif','center','Try the links below to show the various pages on this demo site and to play with editing features<br><br><br><br>',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (8,1,1,3,'mycms Demo Links:',1,'serif','left','<a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=2&referp_id=3\">A Link to Page 2</a><br><a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=3&referp_id=3\">A Link to Page 3</a><br><a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=4&referp_id=3\">A Link to Page 4</a>',2,'times','left',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');

--page 3
INSERT INTO content VALUES (1,1,3,1,'Sample Content Title 1',3,'times','center','This is a test 1',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (2,1,3,2,'Sample Content Title 2',3,'times','center','This is a test 2',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (3,1,3,3,'Sample Content Title 3',3,'times','center','This is a test 3',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (9,1,3,4,'mycms Demo Links:',1,'serif','left','<a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=2&referp_id=3\">A Link to Page 2</a><br><a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=3&referp_id=2\">A Link to Page 3</a><br><a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=4&referp_id=3\">A Link to Page 4</a>',2,'times','left',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (11,1,3,5,'Sample Content Title 6',5,'times','center','This is a test 6',3,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');

-- PAGE 2
INSERT INTO content VALUES (12,1,2,3,'Sample Content Title 7',5,'times','left','This is a test 7',3,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (4,1,2,1,'Sample Content Title 4',3,'time','center','This is a test 4',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (5,1,2,2,'Sample Content Title 5',1,'times','center','This is a test 5',3,'times','left',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','left');
INSERT INTO content VALUES (10,1,2,5,'mycms Demo Links:',1,'serif','left','<a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=2&referp_id=3\">A Link to Page 2</a><br><a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=3&referp_id=3\">A Link to Page 3</a><br><a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=4&referp_page_id=3\">A Link to Page 4</a>',2,'times','left',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (14,1,2,4,'Sample Content Title 8',5,'times','center','This is a test 8',3,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');

--page 4
INSERT INTO content VALUES (15,1,4,1,'Sample Content Title 1',3,'times','center','This is a test 1',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (16,1,4,2,'Sample Content Title 2',3,'times','center','This is a test 2',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (17,1,4,3,'Sample Content Title 3',3,'times','center','This is a test 3',2,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (18,1,4,4,'mycms Demo Links:',1,'serif','left','<a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=2&referp_id=3\">A Link to Page 2</a><br><a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=3&referp_id=3\">A Link to Page 3</a><br><a href=\"http://127.0.0.1/~parasyte/mycms/phase3/?page_id=4&referp_id=3\">A Link to Page 4</a>',2,'times','left',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (19,1,4,5,'Sample Content Title 6',5,'times','center','This is a test 6',3,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');

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


INSERT INTO page VALUES (1,1,0,0,'default','mycms Home Page','mycms: A CMS That Makes Sence',20,'times','left',1048014082,'parasyte@thing.stuff','7739350834',0);
INSERT INTO page VALUES (2,1,1,0,'doubled','Sample Page Title 2','Sample Heading: Page 2',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);
INSERT INTO page VALUES (3,1,2,0,'staggared_reverse','Sample Page Title 3','Sample Heading: Page 3',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);
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


INSERT INTO site VALUES (1,1,'eertwfld','karl','mycmssite',1);

