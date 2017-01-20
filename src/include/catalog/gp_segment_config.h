/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/*-------------------------------------------------------------------------
 *
 * gp_segment_config.h
 *    a segment configuration table
 *
 * $Id: $
 * $Change: $
 * $DateTime: $
 * $Author: $
 *-------------------------------------------------------------------------
 */
#ifndef _GP_SEGMENT_CONFIG_H_
#define _GP_SEGMENT_CONFIG_H_

#include "catalog/genbki.h"

/*
 * Defines for gp_segment_config table
 */
#define GpSegmentConfigRelationName		"gp_segment_configuration"

#define MASTER_DBID 1
#define MASTER_CONTENT_ID (-1)
#define MASTER_ORDER_ID  0
#define STANDBY_ORDER_ID (-1)

/* TIDYCAT_BEGINDEF

   CREATE TABLE gp_segment_configuration
   with (camelcase=GpSegmentConfig, shared=true, oid=false, relid=5036, reltype_oid=6442, toast_oid=2900, toast_index=2901, toast_reltype=2906, content=MASTER_ONLY)
   (
   registration_order integer    ,
   role               "char"     ,
   status             "char"     ,
   port               integer    ,
   hostname           text       ,
   address            text       ,
   description        text
   );

   create unique index on gp_segment_configuration(registration_order) with (indexid=6106, indexname=gp_segment_config_registration_order_index);
   create index on gp_segment_configuration(role) with (indexid=6107, indexname=gp_segment_config_role_index);

   TIDYCAT_ENDDEF
*/
/* TIDYCAT_BEGIN_CODEGEN 

   WARNING: DO NOT MODIFY THE FOLLOWING SECTION: 
   Generated by tidycat.pl version 34
   on Sat Jan  2 21:01:04 2016
*/


/*
 TidyCat Comments for gp_segment_configuration:
  Table is shared, so catalog.c:IsSharedRelation is updated.
  Table does not have an Oid column.
  Table has static type (see pg_types.h).
  Table has TOASTable columns, and TOAST table has static type.
  Table contents are only maintained on MASTER.

*/

/* ----------------
 *		gp_segment_configuration definition.  cpp turns this into
 *		typedef struct FormData_gp_segment_configuration
 * ----------------
 */
#define GpSegmentConfigRelationId	5036

CATALOG(gp_segment_configuration,5036) BKI_SHARED_RELATION BKI_WITHOUT_OIDS
{
	int32	registration_order;	
	char	role;				
	char	status;				
	int32	port;				
	text	hostname;			
	text	address;			
	text	description;		
} FormData_gp_segment_configuration;


/* ----------------
 *		Form_gp_segment_configuration corresponds to a pointer to a tuple with
 *		the format of gp_segment_configuration relation.
 * ----------------
 */
typedef FormData_gp_segment_configuration *Form_gp_segment_configuration;


/* ----------------
 *		compiler constants for gp_segment_configuration
 * ----------------
 */
#define Natts_gp_segment_configuration						7
#define Anum_gp_segment_configuration_registration_order	1
#define Anum_gp_segment_configuration_role					2
#define Anum_gp_segment_configuration_status				3
#define Anum_gp_segment_configuration_port					4
#define Anum_gp_segment_configuration_hostname				5
#define Anum_gp_segment_configuration_address				6
#define Anum_gp_segment_configuration_description			7


/* TIDYCAT_END_CODEGEN */

#endif /*_GP_SEGMENT_CONFIG_H_*/