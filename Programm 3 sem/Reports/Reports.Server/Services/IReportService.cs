using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Reports.DAL.Entities;

namespace Reports.Server.Services
{
    public interface IReportService
    {
        Task<Report> Create(Report.RequestReport requestModel);

        List<Report> GetAll();

        Report FindById(Guid id);
        void Delete(Guid id);

        void Update(Report.RequestReportUpdate requestModel);
    }
}