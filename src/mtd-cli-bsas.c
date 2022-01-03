/* SPDX-License-Identifier: GPL-2.0 */

/*
 * mtd-cli-bsas.c - Make Tax Digital - Business Source Adjustable Summary
 *
 * Copyright (C) 2020 - 2022	Andrew Clayton <andrew@digital-domain.net>
 */

#include <stddef.h>

#include <libmtdac/mtd-bsas.h>

#include "mtd-cli.h"

#define API	bsas

#define API_NAME "Business Source Adjustable Summary"
#define CMDS \
"list-summaries trigger-summary\n\n"\
"Self-Employment\n\n"\
"se-get-summary se-list-summary-adjustments se-update-summary-adjustments\n\n"\
"UK Property Business\n\n"\
"pb-get-summary pb-list-summary-adjustments pb-update-summary-adjustments\n\n"\
"Foreign Property Business\n\n"\
"fp-get-summary fp-list-summary-adjustments fp-update-summary-adjustments"

static const struct endpoint endpoints[] = {
	{
		.name = "list-summaries",
		.func_1 = mtd_bsas_list_summaries,
		.func = FUNC_1,
		.nr_req_args = 0,
		.args = "[[selfEmploymentId=][,[typeOfBusiness={self-employment,uk-property-non-fhl,uk-property-fhl}][,[taxYear=YYYY-YY]]]]"
	}, {
		.name = "trigger-summary",
		.func_1d = mtd_bsas_trigger_summary,
		.func = FUNC_1d,
		.nr_req_args = 1,
		.args = "<file>"
	}, {
		.name = "se-get-summary",
		.func_2 = mtd_bsas_se_get_summary,
		.func = FUNC_2,
		.nr_req_args = 1,
		.args = "bsasId [adjustedStatus={true,false}]"
	}, {
		.name = "se-list-summary-adjustments",
		.func_1 = mtd_bsas_se_list_summary_adjustments,
		.func = FUNC_1,
		.nr_req_args = 1,
		.args = "bsasId"
	}, {
		.name = "se-update-summary-adjustments",
		.func_2d = mtd_bsas_se_update_summary_adjustments,
		.func = FUNC_2d,
		.nr_req_args = 2,
		.args = "<file> bsasId"
	}, {
		.name = "pb-get-summary",
		.func_2 = mtd_bsas_pb_get_summary,
		.func = FUNC_2,
		.nr_req_args = 1,
		.args = "bsasId [adjustedStatus={true,false}]"
	}, {
		.name = "pb-list-summary-adjustments",
		.func_1 = mtd_bsas_pb_list_summary_adjustments,
		.func = FUNC_1,
		.nr_req_args = 1,
		.args = "bsasId"
	}, {
		.name = "pb-update-summary-adjustments",
		.func_2d = mtd_bsas_pb_update_summary_adjustments,
		.func = FUNC_2d,
		.nr_req_args = 2,
		.args = "<file> bsasId"
	}, {
		.name = "fp-get-summary",
		.func_2 = mtd_bsas_fp_get_summary,
		.func = FUNC_2,
		.nr_req_args = 1,
		.args = "bsasId [adjustedStatus={true,false}]"
	}, {
		.name = "fp-list-summary-adjustments",
		.func_1 = mtd_bsas_fp_list_summary_adjustments,
		.func = FUNC_1,
		.nr_req_args = 1,
		.args = "bsasId"
	}, {
		.name = "fp-update-summary-adjustments",
		.func_2d = mtd_bsas_fp_update_summary_adjustments,
		.func = FUNC_2d,
		.nr_req_args = 2,
		.args = "<file> bsasId"
	},

	{ }
};

const struct _endpoint ENDPOINT = {
	.endpoints = endpoints,
	.api_name = API_NAME,
	.cmds = CMDS
};
