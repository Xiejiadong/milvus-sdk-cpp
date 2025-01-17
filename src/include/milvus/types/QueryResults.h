// Licensed to the LF AI & Data foundation under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership. The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <vector>

#include "FieldData.h"

namespace milvus {

/**
 * @brief Results returned by MilvusClient::Query().
 */
class QueryResults {
 public:
    QueryResults() = default;

    /**
     * @brief Constructor
     */
    explicit QueryResults(const std::vector<FieldDataPtr>& output_fields) {
        output_fields_ = output_fields;
    }

    /**
     * @brief Constructor
     */
    explicit QueryResults(std::vector<FieldDataPtr>&& output_fields) {
        output_fields_ = std::move(output_fields);
    }

    /**
     * @brief Get output field data by name.
     */
    FieldDataPtr
    GetFieldByName(const std::string& name) {
        for (FieldDataPtr& field : output_fields_) {
            if (nullptr == field) {
                continue;
            }

            if (field->Name() == name) {
                return field;
            }
        }

        return nullptr;
    }

    /**
     * @brief Get all output fields data.
     */
    const std::vector<FieldDataPtr>&
    OutputFields() const {
        return output_fields_;
    }

 private:
    std::vector<FieldDataPtr> output_fields_;
};

}  // namespace milvus
