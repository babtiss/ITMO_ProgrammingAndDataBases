using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Reports.DAL.Entities;
using Reports.Server.Database;

namespace Reports.Server.Services
{
    public class EmployeeService : IEmployeeService
    {
        private readonly ReportsDatabaseContext _context;

        public EmployeeService(ReportsDatabaseContext context) {
            _context = context;
        }
        public async Task<Employee> Create(string name, Guid bossId)
        {
            var employee = new Employee(name, bossId);
            await _context.Employees.AddAsync(employee);
            await _context.SaveChangesAsync();
            return employee;
        }
        public Employee FindById(Guid id)
        {
            return _context.Employees.FirstOrDefault(x => Equals(x.Id, id));
        }
        public List<Employee> GetAll()
        {
            return _context.Employees.ToList();
        }
        public void Delete(Guid id)
        {
            _context.Employees.Remove(FindById(id));
            _context.SaveChanges();
        }
    }
}