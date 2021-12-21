using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Reports.DAL.Entities;
using Reports.Server.Database;
namespace Reports.Server.Services
{
    public class ReportService : IReportService
    {
        private readonly ReportsDatabaseContext _context;
        public ReportService(ReportsDatabaseContext context) {
            _context = context;
        }
        public async Task<Report> Create(Report.RequestReport requestModel)
        {
            var report = new Report(requestModel.Context, requestModel.EmployeeWhoCreated, requestModel.TaskModel);
            await _context.Reports.AddAsync(report);
            await _context.SaveChangesAsync();
            return report;
        }
        public List<Report> GetAll()
        {
            return _context.Reports.ToList();
        }
        public Report FindById(Guid id)
        {
            return _context.Reports.First(x => Equals(x.Id, id));
        }
        public void Delete(Guid id)
        {
            _context.Reports.Remove(FindById(id));
            _context.SaveChanges();
        }
        public void Update(Report.RequestReportUpdate requestModel)
        {
            var report = FindById(requestModel.Id);
            report.Context = requestModel.Context;
            report.EmployeeWhoCreated = requestModel.EmployeeWhoCreated;
            _context.Update(report);
            _context.SaveChanges();
        }
    }
}